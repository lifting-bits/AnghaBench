#!/bin/bash
#DO Bearer Token
export DO_TOKEN=__DO_TOKEN__

function exit_hook {
DROPLET_ID=$(curl -s http://169.254.169.254/metadata/v1/id)

curl -X DELETE \
    -H "X-Dangerous: true" \
    -H "Authorization: Bearer ${DO_TOKEN}" \
    "https://api.digitalocean.com/v2/droplets/${DROPLET_ID}/destroy_with_associated_resources/dangerous" 
}

# always kill self on exit
trap exit_hook EXIT

export SLACK_HOOK=__SLACK_HOOK__
export ANGHA_BRANCH=__ANGHA_BRANCH__
export RELLIC_BRANCH=__RELLIC_BRANCH__
export RUN_SIZE=__RUN_SIZE__
export LLVM_VERSION=11

apt-get update
apt-get install -yqq rpm curl git python3 python3-pip xz-utils cmake ninja-build build-essential clang-11
python3 -m pip install requests

git clone --depth=1 -b ${RELLIC_BRANCH}  https://github.com/lifting-bits/rellic rellic
git clone --depth=1 -b ${ANGHA_BRANCH}   https://github.com/lifting-bits/AnghaBench.git angha

pushd rellic
# build us a rellic
scripts/build.sh --llvm-version ${LLVM_VERSION}
dpkg -i rellic-build/*.deb
popd

pushd angha

# Install extra requirements if needed
if [[ -f requirements.txt ]]
then
    python3 -m pip install -r requirements.txt
fi

mkdir -p $(pwd)/output

# default to 1k
if [[ "${RUN_SIZE,,}" = "__run_size__" ]]
then
    scripts/download.sh 1k.
elif [[ "${RUN_SIZE,,}" = "1k" ]]
then
    scripts/download.sh 1k.
elif [[ "${RUN_SIZE,,}" = "1m" ]]
then
    scripts/download.sh
else
    echo "Bad run size: ${RUN_SIZE}"
    exit 1
fi

for i in *.tar.xz
do
    tar -xJf $i
done

# Run the benchmark
tool_tests/rellic.py --rellic rellic-decomp-${LLVM_VERSION}.0 \
    --input-dir $(pwd)/bitcode \
    --output-dir $(pwd)/output \
    --slack-notify

# exit hook called here
exit 0