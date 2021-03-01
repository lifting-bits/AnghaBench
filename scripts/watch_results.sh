#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
set -euo pipefail

WATCHDIR=${1:-${DIR}/../results}

echo "Watching: ${WATCHDIR}"

while true
do
  for i in ${WATCHDIR}/*
  do
    printf "% 8d %s\n" "$(find $i -type d -printf . | wc -c)" "$i";
  done | sort -rn
  sleep 10
  clear
done
