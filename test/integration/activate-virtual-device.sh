#!/usr/bin/env bash

# rotctl connects to              - /tmp/easycomm-host-side
# native test program connects to - /tmp/easycomm-controller-side
socat \
  -d -d \
  pty,raw,echo=0,link=/tmp/easycomm-host-side \
  pty,raw,echo=0,link=/tmp/easycomm-controller-side
