# ToB AnghaBench Fork

This is a fork of the [AnghaBench Benchmark Suite](https://github.com/brenocfg/AnghaBench).
This fork includes scripts to build the benchmarks and also includes a means to download pre-compiled benchmarks as well.


## Prerequisites

This script only generates compile commands. You need to have the requisite cross-compilers installed. For example, for `armv7` (armv7 hard float, in this case), you probably want:

```sh
sudo apt install \
  binutils-arm-linux-gnueabihf\
  libstdc++6-armhf-cross\
  gcc-9-arm-linux-gnueabihf
```

Repeat for `arm64`, x86 (`i686`), etc., as necessary

## Building

Use the `generate_compile_commands.py` script to generate compile commands, and GNU `parallel` to invoke the build, like so:

```sh
scripts/generate_compile_commands.py --clang clang-11 -o compile_commands.txt
#Adapted from https://stackoverflow.com/a/11489660
#this is *considerably* faster than `parallel`
#but could be improved more since it forks /bin/sh every time
cores=$(fgrep -c processor /proc/cpuinfo)
xargs --arg-file=compile_commands.txt \
      --max-procs=${cores}  \
      -I{} \
      /bin/sh -c "{}"
```

This will compile the benchmark to bitcode for `x86`, `armv7`, `arm64`, and `x86-64`. Install appropriate cross-compilation tools as needed to get the build to succeed.

Compilation takes about 30 minutes per architecture on a Ryzen 9 5950x.

## Downloading Pre-Built Bitcode

The download script will pull pre-made bitcode for all available architectures. 
There are two sets, a trimmed down version (`1k`, only 1000 files) and the full set (`1m`, one million files).
The `1m` set for each architecture is around 1 GiB in size, compressed.

```sh
# download the 1000 set of bitcode and binaries for each architecture
lifting-tools-ci/datasets/fetch_anghabench.sh --run_size 1k --bitcode --binaries
```

## Tool Usage

The `generate_compile_commands.py` script takes several options to make a file of compilation commands that should be passed to `xargs`.

```
$ scripts/generate_compile_commands.py --help
usage: generate_compile_commands.py [-h] [--clang CLANG] [--source SOURCE] [--dest DEST] [-o OUTFILE]

optional arguments:
  -h, --help            show this help message and exit
  --clang CLANG         Which clang binary to run, default clang-11
  --source SOURCE       where to look for source files
  --dest DEST           where to put bitcode
  -o OUTFILE, --outfile OUTFILE
                        Output file to write, default to stdout
```

The `compress.sh` script compresses compiled bitcode for archiving.
