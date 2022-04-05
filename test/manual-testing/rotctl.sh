#!/usr/bin/env bash
SCRIPT_DIR="$(dirname "$(readlink -f "$0")")"

# start rotctl and use virtual device
# usage:
#   script "device-file"
#   script "device-file" "model-id"
#   script "device-file" "model-id" "verbosity-vvv"

DEVICE_FILE="--rot-file=${SCRIPT_DIR}/../easycomm-endpoint-rotctl"
MODEL="--model=204"
VERBOSITY=""
CONFIG="--set-conf=timeout=900,post_write_delay=100,write_delay=0"
OPTIONAL_COMMANDS="$1"

if [ -n "$OPTIONAL_COMMANDS" ]; then
  # send optional commands, non interactive
  echo "$OPTIONAL_COMMANDS" | rotctl $DEVICE_FILE $MODEL $VERBOSITY -
else
  # interactive
  rotctl $DEVICE_FILE $MODEL $VERBOSITY $CONFIG
fi