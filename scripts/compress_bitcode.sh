#!/bin/bash
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

set -euo pipefail

CLANG=clang-11

pushd ${DIR}/.. &>/dev/null

for archdir in bitcode/*
do
  arch=$(basename ${archdir})
  echo "Compressing ${arch}"
  XZ_OPT=-e9 tar -Ipixz -cf bitcode.${CLANG}.${arch}.tar.xz bitcode/${arch}
done

popd &>/dev/null
