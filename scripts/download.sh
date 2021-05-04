#!/bin/bash
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

set -euo pipefail

CLANG=clang-11

ARCHES=(
  amd64
  arm64
  x86
)

# supported sizes are currently "1k." and empty ("") 
RUNSIZE=${1:-""}

pushd ${DIR}/.. &>/dev/null

for otype in bitcode binaries
do
  for arch in "${ARCHES[@]}"
  do
    bcfile=${otype}.${CLANG}.${arch}.tar.xz
    curl -LO https://anghabench-files-public.nyc3.digitaloceanspaces.com/${CLANG}/${RUNSIZE}${bcfile}
  done
done

popd &>/dev/null
