#!/usr/bin/env python

from pathlib import Path
from os import path
import argparse
import sys
import shutil

MYDIR = path.dirname(path.abspath(__file__))
ARCHMAP = {
        'amd64' : ["--target=x86_64-pc-linux-gnu"],
        'arm64' : ["--target=aarch64-linux-gnu", "-isystem/usr/aarch64-linux-gnu/include"],
        'x86' :   ["--target=i686-linux-gnu"],
        }

EXTRA_OPTIONS = [
  '-O1', # do some basic opts
  '-ggdb', # emit debug info
  '-pipe', # use less filesystem
  '-w', # ignore warnings
]

def emit_mk_dir(of, dstdir):
  of.write(f"mkdir -p {dstdir}\n")

def emit_clang_bc_cmdline(of, clang, arch, dstfile, srcfile):
  cmd_line = [clang]
  # Options every clang invocation gets
  cmd_line.extend(EXTRA_OPTIONS)
  # architecture specific args
  cmd_line.extend(ARCHMAP[arch])
  # Generate bitcode and not do a full compilation
  cmd_line.extend(["-emit-llvm", "-c", "-o", dstfile, srcfile])

  # write out the cmdline
  of.write(" ".join(cmd_line))
  of.write("\n")

if __name__ == "__main__":


  parser = argparse.ArgumentParser()
  parser.add_argument('--clang', default="clang-11", help="Which clang binary to run, default clang-11")
  parser.add_argument('--source', default=f"{MYDIR}/../source", help="where to look for source files")
  parser.add_argument('--dest', default=f"{MYDIR}/../bitcode", help="where to put bitcode")
  parser.add_argument('-o', '--outfile', default="/dev/stdout", help="Output file to write, default to stdout")

  args = parser.parse_args()

  if shutil.which(args.clang) is None:
    sys.stderr.write(f"Could not find clang command: {args.clang}\n")
    sys.exit(1)

  source_path = Path(args.source)
  # find every .c file
  sources = list(source_path.rglob('*.c'))

  # find the last part of the source path, so that we can replicate source tree in destination dir
  last_source_part = source_path.parts[-1]

  if 0 == len(sources):
    sys.stderr.write(f"Could not find any C source in {args.source}\n")
    sys.exit(1)

  worklist = []
  last_dir = ""

  with open(args.outfile, 'w') as of:
    for (arch, cmdargs) in ARCHMAP.items():
      destination = Path(f"{args.dest}/{arch}")

      for source in sources:

        # convert source filename to one in the destination directory tree
        # and ending in ".bc"
        source = str(source)
        f, _ = path.splitext(source)
        bcfile = Path(f"{f}.bc")
        idx = bcfile.parts.index(last_source_part)
        new_path = str(destination.joinpath(*bcfile.parts[idx+1:]))

        # emit the mkdir command to create the output directory
        # skip emitting duplicates, since many files share the same subdirectory
        new_dir = path.dirname(new_path)
        if new_dir != last_dir:
          last_dir = new_dir
          emit_mk_dir(of, new_dir)

        # save the arch/source/dest pair to avoid recomputing it
        worklist.append( (arch, new_path, source,) )

      # emit clang command lines to output bitcode
      for item in worklist:
        emit_clang_bc_cmdline(of, args.clang, item[0], item[1], item[2])
