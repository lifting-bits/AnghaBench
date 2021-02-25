# ToB AnghaBench Fork

This is a fork of the [AnghaBench Benchmark Suite](https://github.com/brenocfg/AnghaBench).
This fork includes scripts to build the benchmarks and also includes a means to download pre-compiled benchmarks as well.

## Building

Use the `generate_compile_commands.py` script to generate compile commands, and GNU `parallel` to invoke the build, like so:

```sh
scripts/generate_compile_commands.py --clang clang-11 -o compile_commands.txt
parallel :::: compile_commands.txt
```

This will compile the benchmark to bitcode for `x86`, `arm64`, and `x86-64`. Install appropriate cross-compilation tools as needed to get the build to succeed.

Compilation takes about 30 minutes per architecture on a Ryzen 9 5950x and the output is around 23 GiB of bitcode.

## Downloading Pre-Built Bitcode

The download script will pull pre-made bitcode for all available architectures. Each architecture is around 1 GiB in size, compressed.

```sh
scripts/download.sh
```

## Tool Usage

The `generate_compile_commands.py` script takes several options to make a file of compilation commands that should be passed to `parallel`.

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

The `download.sh` script will download pre-made bitcode archives.o

The `compress.sh` script compresses compiled bitcode for archiving.
