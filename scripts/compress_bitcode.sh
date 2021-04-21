#!/bin/bash
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

set -euo pipefail

CLANG=clang-11

pushd ${DIR}/../compiled &>/dev/null

for otype in bitcode binaries
do
  for archdir in ${otype}/*
  do
    arch=$(basename ${archdir})
    echo "Compressing ${otype} ${arch}"
    XZ_OPT=-e9 tar -Ipixz -cf ${otype}.${CLANG}.${arch}.tar.xz ${otype}/${arch}
  done
done

popd &>/dev/null
