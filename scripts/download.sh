#!/bin/bash
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

set -euo pipefail

CLANG=clang-11

ARCHES=(
  amd64
  arm64
  x86
)


pushd ${DIR}/.. &>/dev/null

for arch in "${ARCHES[@]}"
do
  bcfile=bitcode.${CLANG}.${arch}.tar.xz
  curl -LO https://anghabench-files-public.nyc3.digitaloceanspaces.com/${CLANG}/${bcfile}
done

popd &>/dev/null
