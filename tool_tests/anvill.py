#!/usr/bin/env python3
import argparse
import sys
import shutil
import logging
import subprocess
from os import path
import os
from pathlib import Path
from tqdm import tqdm
from multiprocessing import Pool
from functools import partial
from toolcmd import ToolCmd

log = logging.getLogger("anvill_test_suite")
log.addHandler(logging.StreamHandler())
#log.setLevel(logging.DEBUG)
log.setLevel(logging.INFO)


MYDIR = path.dirname(path.abspath(__file__))

# given some input bitocode, run it through anvill record outputs

class AnvillCmd(ToolCmd):

    def make_tool_cmd(self):
        f = self.infile.stem
        jsonfile = f"{self.index}-{f}.json"
        self.tmpout = self.outdir.joinpath("work").joinpath(jsonfile)

        #python3 -m anvill --bin_in foo.elf --spec_out foo.json 
        log.debug(f"Setting tmpout to: {self.tmpout}")
        args = self.tool.split()
        args.extend([
            "--bin_in",
            str(self.infile),
            "--spec_out",
            str(self.tmpout),
            "--log_file",
            "/dev/stderr",
        ])
        return args

    def save(self):
        if self.rc is None:
            raise RuntimeError("Return code never set")

        pth = self.outdir.joinpath(self.get_output_path())
        pth = pth.joinpath(self.infile.relative_to(self.source_base))

        log.debug(f"Making dir: {pth}")
        os.makedirs(pth, exist_ok=True)

        input_name = pth.joinpath("input.elf")
        shutil.copyfile(self.infile, input_name)

        if self.rc == 0:
            output_name = pth.joinpath("output.json")
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

def run_anvill(anvill, output_dir, failonly, source_path, input_and_idx):
    idx, input_file = input_and_idx
    cmd = AnvillCmd(anvill, input_file, output_dir, source_path, idx)

    retcode = cmd.run()
    log.debug(f"Anvill run returned {retcode}")

    if not failonly:
        cmd.save()
    elif failonly and retcode != 0:
        log.debug("Saving anvill failure case")
        cmd.save()
    else:
        log.debug("Successful anvill invocation not saved due to --only-fails=True")

    return cmd


if __name__ == "__main__":

    # anvill.py
    #   --input-dir input_dir
    #   --output-dir output_dir
    #   --only-fails
    #   --slack-notify

    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--anvill", default="python3 -m anvill", help="Which anvill to run"
    )
    parser.add_argument(
        "--input-dir",
        default=f"{MYDIR}/../compiled/binaries",
        help="where to look for binary inputs"
    )
    parser.add_argument(
        "--output-dir",
        default=f"{MYDIR}/../results/anvill",
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
        help="Notify slack about stats",
    )

    args = parser.parse_args()

    test_anvill_args = args.anvill.split()
    test_anvill_args.append("-h")
    anvill_test = subprocess.run(test_anvill_args, stderr=subprocess.DEVNULL, stdout=subprocess.DEVNULL)
    if anvill_test.returncode != 0:
        sys.stderr.write(f"Could not find anvill command: {args.anvill}\n")
        sys.exit(1)

    source_path = Path(args.input_dir)
    dest_path = Path(args.output_dir)
    # get all the bitcode
    log.info(f"Listing files in {str(source_path)}")
    sources = list(source_path.rglob("*.elf"))
    log.info(f"Found {len(sources)} ELF files")

    if sources:
        workdir = str(dest_path.joinpath("work"))
        log.debug(f"Making work dir [{workdir}]")
        os.makedirs(workdir, exist_ok=True)

    
    num_cpus = os.cpu_count()
    max_items = len(sources)
    apply_anvill = partial(run_anvill, args.anvill, dest_path, args.only_fails, source_path)

    with Pool(processes=num_cpus) as p:
        with tqdm(total=max_items) as pbar:
            for _ in p.imap_unordered(apply_anvill, enumerate(sources)):
                pbar.update()
