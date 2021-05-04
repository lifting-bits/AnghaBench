#!/usr/bin/env python3

import requests
import os
import json
from datetime import datetime
import argparse
import sys

#curl -X POST "https://api.digitalocean.com/v2/droplets" \
#      -d'{"name":"metadata.example.com","region":"nyc3","size":"s-1vcpu-1gb","vpc_uuid":"c33931f2-a26a-4e61-b85c-4e95a2ec431b","image":"ubuntu-20-04-x64","user_data":
#"'"$(cat ~/user-data.yml)"'",
#      "ssh_keys":[ < SSH KEY IDs > ]}' \
#      -H "Authorization: Bearer $TOKEN" \
#      -H "Content-Type: application/json"


def replace_vars(vars, script):
    for k,v in vars.items():
        script = script.replace(f"__{k}__", v)
    
    return script


def make_do_droplet(token, droplet_info):
    url = "https://api.digitalocean.com/v2/droplets" 
    resp = requests.post(
        url, data = json.dumps(droplet_info),
        headers = {'Content-Type': 'application/json',
            'Authorization': f'Bearer {token}'})

    if resp.status_code < 200 or resp.status_code >= 300:
        raise RuntimeError(f"Could not make DO Droplet: {str(resp)}: {resp.content}")
    else:
        sys.stdout.write("Successfully created new droplet!\n")

if __name__ == "__main__":

    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--name", default=f"ci-run-{datetime.today().strftime('%Y-%m-%d')}", help="Name to identify this instance")
    parser.add_argument(
        "--token", default=os.environ.get("DO_TOKEN", ""), help="DO Access Token")

    parser.add_argument("--angha-branch", default="master", help="Which branch of AnghaBench to use")
    parser.add_argument("--env-vars", default="", help="Extra list of environment variables. Form [var=value,var2=value2,...]")
    parser.add_argument("--script", required=True, help="which script to run")

    parser.add_argument(
        "--instance",
        default="c-32",
        help="Instance type to create"
    )

    args = parser.parse_args()

    do_data = os.path.realpath(args.script)

    if not os.path.exists(do_data):
        sys.stderr.write(f"Could not open startup script [{do_data}]\n")
        sys.exit(1)

    if not args.token:
        sys.stderr.write("Please set a DO token in the DO_TOKEN env var\n")
        sys.exit(1)

    if "SLACK_HOOK" not in os.environ:
        sys.stderr.write("Please set SLACK_HOOK env var\n")
        sys.exit(1)

    sys.stdout.write(f"Creating DO droplet [{args.name}] of type [{args.instance}]\n")


    VARS_TO_FIX = {
        "DO_TOKEN": args.token,
        "SLACK_HOOK": os.environ["SLACK_HOOK"],
        "ANGHA_BRANCH": args.angha_branch,
    }

    if args.env_vars:
        parts = args.env_vars.split(',')
        for prt in parts:
            p = prt.split('=')
            if len(p) > 1:
                VARS_TO_FIX[p[0]] = p[1]

    do_script = replace_vars(VARS_TO_FIX, open(do_data, 'r').read())

    di = { 
        "name": args.name,
        "region": "nyc3",
        "size": args.instance,
        "image": "ubuntu-20-04-x64",
        "ssh_keys": None,
        "user_data": do_script,
        "tags": ["ci", "anghabench"],
    }

    make_do_droplet(args.token, di)