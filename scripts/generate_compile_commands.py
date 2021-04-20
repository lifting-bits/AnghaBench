#!/usr/bin/env python3

from pathlib import Path
from os import path
import argparse
import sys
import shutil

MYDIR = path.dirname(path.abspath(__file__))
ARCHMAP = {
    "amd64": ["--target=x86_64-pc-linux-gnu"],
    "arm64": ["--target=aarch64-linux-gnu", "-isystem/usr/aarch64-linux-gnu/include"],
    "x86": ["--target=i686-linux-gnu"],
    "armv7": ["--target=arm-linux-gnueabihf", "-march=armv7a", "-isystem/usr/arm-linux-gnueabihf/include"],
}

EXTRA_OPTIONS = [
    "-O1",  # do some basic opts
    "-ggdb",  # emit debug info
    "-pipe",  # use less filesystem
    "-w",  # ignore warnings
]


def emit_mk_dir(of, dstdir):
    of.write(f"mkdir -p {dstdir}\n")


def emit_clang_cmdline(of, clang, special_opts, arch, dstfile, srcfile, suffix):
    cmd_line = [clang]
    # Options every clang invocation gets
    cmd_line.extend(EXTRA_OPTIONS)
    # architecture specific args
    cmd_line.extend(ARCHMAP[arch])
    # special arguments for this specific invocation
    if special_opts:
        cmd_line.extend(special_opts)
    # Generate bitcode and not do a full compilation
    cmd_line.extend(["-o", str(dstfile.with_suffix(suffix)), str(srcfile)])

    # write out the cmdline
    of.write(" ".join(cmd_line))
    of.write("\n")


def emit_clang_bc_cmdline(of, clang, arch, dstfile, srcfile):
    emit_clang_cmdline(
        of, clang, ["-emit-llvm", "-c"], arch, dstfile, srcfile, suffix=".bc"
    )


def emit_clang_elf_cmdline(of, clang, arch, dstfile, srcfile):
    emit_clang_cmdline(of, clang, [], arch, dstfile, srcfile, suffix=".elf")


def emit_mkdir_command(
    of, source_file, source_dir_base, dest_dir_base, previous_dir=None
):
    # convert source filename to one in the destination directory tree
    idx = source_file.parts.index(source_dir_base)
    new_path = dest_dir_base.joinpath(*source_file.parts[idx + 1 :])

    # emit the mkdir command to create the output directory
    # skip emitting duplicates, since many files share the same subdirectory
    new_dir = new_path.parent
    if new_dir != previous_dir:
        emit_mk_dir(of, new_dir)
    return new_dir


if __name__ == "__main__":

    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--clang",
        default="clang-11",
        help="Which clang binary to run, default clang-11",
    )
    parser.add_argument(
        "--source", default=f"{MYDIR}/../source", help="where to look for source files"
    )
    parser.add_argument(
        "--dest", default=f"{MYDIR}/../compiled", help="where to put output"
    )
    parser.add_argument(
        "--emit-bitcode",
        default=False,
        action="store_true",
        help="Emit commands to compile to bitcode",
    )
    parser.add_argument(
        "--emit-binaries",
        default=False,
        action="store_true",
        help="Emit commands to compile binaries",
    )
    parser.add_argument(
        "-o",
        "--outfile",
        default="/dev/stdout",
        help="Output file to write, default to stdout",
    )

    args = parser.parse_args()

    if not args.emit_bitcode and not args.emit_binaries:
        sys.stderr.write("Nothing to do.\n")
        sys.stderr.write("Please specify --emit-bitcode or --emit-binaries\n")
        sys.exit(1)

    if shutil.which(args.clang) is None:
        sys.stderr.write(f"Could not find clang command: {args.clang}\n")
        sys.exit(1)

    source_path = Path(args.source)
    # find every .c file
    sources = list(source_path.rglob("*.c"))

    # find the last part of the source path, so that we can replicate source tree in destination dir
    last_source_part = source_path.parts[-1]

    if 0 == len(sources):
        sys.stderr.write(f"Could not find any C source in {args.source}\n")
        sys.exit(1)

    worklist = []
    previous_dir = None

    output_styles = []
    emit_functions = {}
    if args.emit_bitcode:
        output_styles.append("bitcode")
        emit_functions["bitcode"] = emit_clang_bc_cmdline
    if args.emit_binaries:
        output_styles.append("binaries")
        emit_functions["binaries"] = emit_clang_elf_cmdline

    with open(args.outfile, "w") as of:
        for (arch, cmdargs) in ARCHMAP.items():
            for outstyle in output_styles:
                destination = Path(f"{args.dest}/{outstyle}/{arch}")
                for source in sources:
                    previous_dir = emit_mkdir_command(
                        of, source, last_source_part, destination, previous_dir
                    )
                    # save the arch/source/dest pair to avoid recomputing it
                    worklist.append(
                        (
                            arch,
                            previous_dir.joinpath(source.name),
                            source,
                            outstyle,
                        )
                    )

        # emit clang command lines to output bitcode
        for item in worklist:
            emit_functions[item[3]](
                of, args.clang, arch=item[0], dstfile=item[1], srcfile=item[2]
            )
