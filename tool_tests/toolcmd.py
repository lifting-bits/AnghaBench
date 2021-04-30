import re
import logging
import signal
import os
import subprocess

log = logging.getLogger("tool_invoker")
log.addHandler(logging.StreamHandler())
log.setLevel(logging.INFO)

FILE_NAME_RE = re.compile("([^/\s]+\.[^/\s]+:\d+)")
PYTHON_ERROR_RE = re.compile('([^/\s]+\.py)", line (\d+)')

class ToolCmd:
    def __init__(self, tool, infile, outdir, source_base, index, stats):
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
        self.stats = stats

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
            self.stats.inc_stat("program_runs")
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
            self.stats.inc_stat("program_timeouts")
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
