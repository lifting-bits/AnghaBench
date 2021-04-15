#!/usr/bin/env python3
import argparse
import sys
import shutil
import logging
import subprocess
import signal
from os import path, strerror
import os
from pathlib import Path
from tqdm import tqdm
from multiprocessing import Pool
from functools import partial
import re

log = logging.getLogger("rellic_test_suite")
log.addHandler(logging.StreamHandler())
#log.setLevel(logging.DEBUG)
log.setLevel(logging.INFO)


MYDIR = path.dirname(path.abspath(__file__))
FILE_NAME_RE = re.compile("([^/\s]+\.[^/\s]+:\d+)")

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


class RellicCmd:
    def __init__(self, rellic, infile, outdir, source_base, index):
        self.source_base = source_base
        self.index = index
        self.infile = infile
        self.outdir = outdir
        self.rellic = rellic
        self.tmpout = None
        self.cmd = self.make_rellic_cmd()
        self.rc = None
        self.out = None
        self.err = None

    def set_output(self, rc, out, err):
        self.rc = rc
        self.out = out
        self.err = err

    def make_rellic_cmd(self):
        f = self.infile.stem
        cfile = f"{self.index}-{f}.c"
        self.tmpout = self.outdir.joinpath("work").joinpath(cfile)

        # rellic -logtostderr -input /input/dir/foo.bc -output /output/dir/work/foo.c
        log.debug(f"Setting tmpout to: {self.tmpout}")
        args = [
            self.rellic,
            "--lower_switch",
            "--remove_phi_nodes",
            "-logtostderr",
            "-input",
            str(self.infile),
            "-output",
            str(self.tmpout),
        ]
        return args

    def get_output_path(self):
        rc_to_path = {
            -131: "timeout",
            -130: "oserror",
            -129: "zero-sized-output",
            -signal.SIGBUS: "sigbus",
            -signal.SIGSEGV: "sigsegv",
            -signal.SIGABRT: "sigabrt",
            -signal.SIGILL: "sigill",
            0: "success",
        }

        if self.rc != -signal.SIGABRT:
            return rc_to_path.get(self.rc, "unknown")
        else:
            # First, check for a fatal error in the style of:
            # F0415 05:22:54.866288 437680 IRToASTVisitor.cpp:123] Unknown LLVM Type
            # Check only lines starting with 'F' since those are the fatal errors
            for ln in self.err.splitlines():
                if ln.startswith("F"):
                    fname = FILE_NAME_RE.search(ln)
                    if fname:
                        return fname.group(0)

            # Next, check for more generic filename matches in the whole message
            # example:
            # UNREACHABLE executed at /__w/cxx-common/cxx-common/vcpkg/buildtrees/llvm-11/src/org-11.0.0-8ebd641fb6.clean/llvm/lib/Support/APFloat.cpp:154!
            fname = FILE_NAME_RE.search(self.err)
            if fname:
                return fname.group(0)
            
            # default to normal sigabrt handler
            return rc_to_path.get(self.rc, "unknown")

    def save(self):

        if self.rc is None:
            raise RuntimeError("Return code never set")

        pth = self.outdir.joinpath(self.get_output_path())
        pth = pth.joinpath(self.infile.relative_to(self.source_base))

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
            out.write(self.out)

        dumperr = pth.joinpath("stderr")
        with open(dumperr, "w") as err:
            err.write(self.err)

        repro = pth.joinpath("repro.sh")
        with open(repro, 'w') as reprofile:
            reprofile.write("#!/bin/sh\n")
            reprofile.write(" ".join(self.cmd))
            reprofile.write("\n")

    def __del__(self):
        if self.tmpout:
            log.debug(f"Unlinking on delete {self.tmpout}")
            try:
                os.unlink(self.tmpout)
            except FileNotFoundError as fnf:
                log.debug(f"Tried to delete a file that doesn't exist: {self.tmpout}")

    def run(self):

        try:
            log.debug(f"Running [{self.cmd}]")
            rellic_run = subprocess.run(
                self.cmd,
                universal_newlines=True,
                check=True,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                timeout=120, # two minutes should be more than enough
            )
        except OSError as oe:
            log.debug("Rellic invocation hit OS error")
            self.set_output(-130, "", oe.strerror)
            return -130
        except subprocess.CalledProcessError as cpe:
            log.debug("Rellic invocation errored")
            self.set_output(cpe.returncode, cpe.stdout, cpe.stderr)
            return cpe.returncode
        except subprocess.TimeoutExpired as tme:
            log.debug("Rellic hit a timeout")
            self.set_output(-131, tme.stdout, tme.stderr)
            return -131

        if 0 == os.path.getsize(self.tmpout):
            self.set_output(
                -129, rellic_run.stdout, rellic_run.stderr + "\n" + "Zero sized output"
            )
            return -129

        # returncode should always be zero
        self.set_output(rellic_run.returncode, rellic_run.stdout, rellic_run.stderr)
        return rellic_run.returncode


def run_rellic(rellic, output_dir, failonly, source_path, input_and_idx):
    idx, input_file = input_and_idx
    cmd = RellicCmd(rellic, input_file, output_dir, source_path, idx)

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
        help="Notify slack about stats",
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
    apply_rellic = partial(run_rellic, args.rellic, dest_path, args.only_fails, source_path)

    with Pool(processes=num_cpus) as p:
        with tqdm(total=max_items) as pbar:
            for _ in p.imap_unordered(apply_rellic, enumerate(sources)):
                pbar.update()
