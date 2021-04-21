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

log = logging.getLogger("anvill_test_suite")
log.addHandler(logging.StreamHandler())
#log.setLevel(logging.DEBUG)
log.setLevel(logging.INFO)


MYDIR = path.dirname(path.abspath(__file__))
FILE_NAME_RE = re.compile("([^/\s]+\.[^/\s]+:\d+)")
PYTHON_ERROR_RE = re.compile('([^/\s]+\.py)", line (\d+)')

# given some input bitocode, run it through anvill record outputs

class ToolCmd:
    def __init__(self, tool, infile, outdir, source_base, index):
        self.source_base = source_base
        self.index = index
        self.infile = infile
        self.outdir = outdir
        self.tool = tool
        self.tmpout = None
        self.cmd = self.make_tool_cmd()
        self.rc = None
        self.out = None
        self.err = None

    def set_output(self, rc, out, err):
        self.rc = rc
        self.out = out
        self.err = err

    def make_tool_cmd(self):
        raise RuntimeError("Please override make_tool_cmd")
    
    def python_traceback(self, msg):
        if not msg:
            return None

        for ln in reversed(msg.splitlines()):
            fname = PYTHON_ERROR_RE.search(ln)
            if fname:
                return f"{fname.group(1)}:{fname.group(2)}"
        
        return None

    def c_abort(self, msg):
        # First, check for a fatal error in the style of:
        # F0415 05:22:54.866288 437680 IRToASTVisitor.cpp:123] Unknown LLVM Type
        # Check only lines starting with 'F' since those are the fatal errors
        if not msg:
            return None

        for ln in msg.splitlines():
            if ln.startswith("F"):
                fname = FILE_NAME_RE.search(ln)
                if fname:
                    return fname.group(1)

        # Next, check for more generic filename matches in the whole message
        # example:
        # UNREACHABLE executed at /__w/cxx-common/cxx-common/vcpkg/buildtrees/llvm-11/src/org-11.0.0-8ebd641fb6.clean/llvm/lib/Support/APFloat.cpp:154!
        fname = FILE_NAME_RE.search(msg)
        if fname:
            return fname.group(1)
        
        # default to normal handler
        return None

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
            1: "PythonAssertion",
        }

        default_location = rc_to_path.get(self.rc, f"unknown_{self.rc}")
        if self.rc == 1:
            return self.python_traceback(self.err) or default_location
        elif self.rc == -signal.SIGABRT:
            return self.c_abort(self.err) or default_location
        else:
            return default_location

    def save(self):
        raise RuntimeError("Please implement the save() method")

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
            tool_run = subprocess.run(
                args=self.cmd,
                universal_newlines=True,
                check=True,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                timeout=120, # two minutes should be more than enough
            )
        except OSError as oe:
            log.debug("Tool invocation hit OS error")
            self.set_output(-130, "", oe.strerror)
            return -130
        except subprocess.CalledProcessError as cpe:
            log.debug("Tool invocation errored")
            self.set_output(cpe.returncode, cpe.stdout, cpe.stderr)
            return cpe.returncode
        except subprocess.TimeoutExpired as tme:
            log.debug("Tool hit a timeout")
            self.set_output(-131, tme.stdout, tme.stderr)
            return -131

        if 0 == os.path.getsize(self.tmpout):
            self.set_output(
                -129, tool_run.stdout, tool_run.stderr + "\n" + "Zero sized output"
            )
            return -129

        # returncode should always be zero
        self.set_output(tool_run.returncode, tool_run.stdout, tool_run.stderr)
        return tool_run.returncode

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
