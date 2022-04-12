#!/usr/bin/env bash
SCRIPT_DIR="$(dirname "$(readlink -f "$0")")"

# start rotctl and use virtual device
# usage:
#   interactive: script
#   single shot: script "optional rotctl commands"

DEVICE_FILE="--rot-file=${SCRIPT_DIR}/../easycomm-endpoint-rotctl"
#MODEL="--model=201" # easycomm 1
#MODEL="--model=202" # easycomm 2
MODEL="--model=204" # easycomm 3
VERBOSITY=""
CONFIG="--set-conf=timeout=900,post_write_delay=0,write_delay=0"
OPTIONAL_COMMANDS="$1"

if [ -n "$OPTIONAL_COMMANDS" ]; then
  # send optional commands, non interactive
  echo "$OPTIONAL_COMMANDS" | rotctl $DEVICE_FILE $MODEL $VERBOSITY -
else
  # interactive
  rotctl $DEVICE_FILE $MODEL $VERBOSITY $CONFIG
fi
