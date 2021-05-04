#!/usr/bin/env python3
import argparse
import sys
import shutil
import logging
from os import path
import os
from pathlib import Path
from tqdm import tqdm
from multiprocessing import Pool
from multiprocessing.pool import ThreadPool
from functools import partial
from toolcmd import ToolCmd
from stats import Stats
from slack import Slack
from datetime import datetime
from io import StringIO

log = logging.getLogger("rellic_test_suite")
log.addHandler(logging.StreamHandler())
#log.setLevel(logging.DEBUG)
log.setLevel(logging.INFO)


MYDIR = path.dirname(path.abspath(__file__))
# given some input bitocode, run it through rellic and record outputs


# Output dir will have:
# output_dir/
#  success/
#    testnumber.arch.original_input_file/
#      bitcode.bc
#      output.c
#      stdout
#      stderr
#  segv/
#   testnumber.arch.original_input_file/
#      bitcode.bc
#      stdout
#      stderr
#      repro.sh
#  abort/
#   testnumber.arch.original_input_file/
#      bitcode.bc
#      stdout
#      stderr
#      repro.sh
#  other/
#   testnumber.arch.original_input_file/
#      bitcode.bc
#      stdout
#      stderr
#      repro.sh
#


class RellicCmd(ToolCmd):

    def make_tool_cmd(self):
        f = self.infile.stem
        cfile = f"{self.index}-{f}.c"
        self.tmpout = self.outdir.joinpath("work").joinpath(cfile)

        # rellic -logtostderr -input /input/dir/foo.bc -output /output/dir/work/foo.c
        log.debug(f"Setting tmpout to: {self.tmpout}")
        args = [
            self.tool,
            "--lower_switch",
            "--remove_phi_nodes",
            "-logtostderr",
            "-input",
            str(self.infile),
            "-output",
            str(self.tmpout),
        ]
        return args

    def save(self):

        if self.rc is None:
            raise RuntimeError("Return code never set")

        out_path_name = self.get_output_path()
        pth = self.outdir.joinpath(out_path_name)
        pth = pth.joinpath(self.infile.relative_to(self.source_base))

        self.stats.add_stat(f"output.{out_path_name}", str(self.infile))

        log.debug(f"Making dir: {pth}")
        os.makedirs(pth, exist_ok=True)

        input_name = pth.joinpath("input.bc")
        shutil.copyfile(self.infile, input_name)

        if self.rc == 0:
            output_name = pth.joinpath("output.c")
            log.debug(f"Copying {self.tmpout} to {output_name}")
            shutil.copyfile(self.tmpout, output_name)

        dumpout = pth.joinpath("stdout")
        with open(dumpout, "w") as out:
            if type(self.out) is bytes:
                out.buffer.write(self.out)
            else:
                out.write(str(self.out))

        dumperr = pth.joinpath("stderr")
        with open(dumperr, "w") as err:
            if type(self.err) is bytes:
                err.buffer.write(self.err)
            else:
                err.write(str(self.err))

        repro = pth.joinpath("repro.sh")
        with open(repro, 'w') as reprofile:
            reprofile.write("#!/bin/sh\n")
            reprofile.write(" ".join(self.cmd))
            reprofile.write("\n")


def run_rellic(rellic, output_dir, failonly, source_path, stats, input_and_idx):
    idx, input_file = input_and_idx
    cmd = RellicCmd(rellic, input_file, output_dir, source_path, idx, stats)

    retcode = cmd.run()
    log.debug(f"Rellic run returned {retcode}")

    if not failonly:
        cmd.save()
    elif failonly and retcode != 0:
        log.debug("Saving rellic failure case")
        cmd.save()
    else:
        log.debug("Successful rellic invocation not saved due to --only-fails=True")

    return cmd


if __name__ == "__main__":

    # rellic.py
    #   --input-dir input_dir
    #   --output-dir output_dir
    #   --only-fails
    #   --slack-notify

    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--rellic", default="rellic-decomp-11.0", help="Which rellic to run"
    )
    parser.add_argument(
        "--input-dir",
        default=f"{MYDIR}/../bitcode",
        help="where to look for source files",
    )
    parser.add_argument(
        "--output-dir",
        default=f"{MYDIR}/../results/rellic",
        help="where to put results",
    )
    parser.add_argument(
        "--only-fails",
        default=False,
        action="store_true",
        help="Only output failing cases",
    )
    parser.add_argument(
        "--slack-notify",
        default=False,
        action="store_true",
        help="Notify slack. SLACK_HOOK env var for the webhook",
    )

    args = parser.parse_args()

    if shutil.which(args.rellic) is None:
        sys.stderr.write(f"Could not find rellic command: {args.rellic}\n")
        sys.exit(1)

    source_path = Path(args.input_dir)
    dest_path = Path(args.output_dir)
    # get all the bitcode
    log.info(f"Listing files in {str(source_path)}")
    sources = list(source_path.rglob("*.bc"))
    log.info(f"Found {len(sources)} bitcode files")

    if sources:
        workdir = str(dest_path.joinpath("work"))
        log.debug(f"Making work dir [{workdir}]")
        os.makedirs(workdir, exist_ok=True)

    
    num_cpus = os.cpu_count()
    max_items = len(sources)
    rellic_stats = Stats()
    rellic_stats.set_stat("start_time", str(datetime.now()))
    apply_rellic = partial(run_rellic, args.rellic, dest_path, args.only_fails, source_path, rellic_stats)

    #with Pool(processes=num_cpus) as p:
    with ThreadPool(num_cpus) as p:
        with tqdm(total=max_items) as pbar:
            for _ in p.imap_unordered(apply_rellic, enumerate(sources)):
                pbar.update()

    rellic_stats.set_stat("end_time", str(datetime.now()))

    if args.slack_notify:
        msg_hook = os.environ.get("SLACK_HOOK", None)

        if not msg_hook:
            sys.stderr.write("Invalid webhook in SLACK_HOOK env var")

        slack_msg = Slack(msg_hook)
        slack_msg.add_header(f"Rellic AnghaBench Run Statistics")
        slack_msg.add_block(f"Input directory: `{args.input_dir}`")
        slack_msg.add_divider()

        with StringIO() as stat_msg:
            rellic_stats.print_stats(stat_msg)
            slack_msg.add_block(stat_msg.getvalue())

        slack_msg.add_divider()

        with StringIO() as fail_msg:
            max_num_fails = 10
            slack_msg.add_block(f"Top {max_num_fails}:")
            rellic_stats.print_fails(fail_count=max_num_fails, output=fail_msg)
            slack_msg.add_block(fail_msg.getvalue())
        
        slack_msg.post()