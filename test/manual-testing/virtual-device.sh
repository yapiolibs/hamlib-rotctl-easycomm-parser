#!/usr/bin/env bash
SCRIPT_DIR="$(dirname "$(readlink -f "$0")")"
# usage:
#   script
#   script "/path/to/temporary/edpoint/a/symlink"
#   script "/path/to/temporary/edpoint/a/symlink "/path/to/temporary/edpoint/b/symlink"
#
# rotctl connects to one end point, native test program to the other

ENDPOINT_A="${SCRIPT_DIR}/../easycomm-endpoint-rotctl"
ENDPOINT_B="${SCRIPT_DIR}/../easycomm-endpoint-test-program"

if [ x"$1" != x ]; then
  ENDPOINT_A="${1}"
fi

if [ x"$2" != x ]; then
  ENDPOINT_B="${2}"
fi

socat \
  -d -d \
  pty,raw,echo=0,link=${ENDPOINT_A} \
  pty,raw,echo=0,link=${ENDPOINT_B}
