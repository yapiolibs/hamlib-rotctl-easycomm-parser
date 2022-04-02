#!/usr/bin/env bash
SCRIPT_DIR="$(dirname "$(readlink -f "$0")")"

# start test program and listen to virtual device
${SCRIPT_DIR}/../.pio/build/native/program  /tmp/easycomm-controller-side
