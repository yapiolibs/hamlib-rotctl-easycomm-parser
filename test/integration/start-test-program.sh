#!/usr/bin/env bash
SCRIPT_DIR="$(dirname "$(readlink -f "$0")")"

PROGRAM="${SCRIPT_DIR}/../.pio/build/native/program"
ENDPOINT="${SCRIPT_DIR}/../easycomm-endpoint-test-program"

# start test program and listen to virtual device
$PROGRAM "$ENDPOINT"
