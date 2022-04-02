#!/usr/bin/env bash

# (./activate-virtual-device.sh > /dev/null 2&1 &)
# (./start-test-program.sh > /dev/null 2&1 &)
# ./test.sh "\\get_pos\\reset" "expected output"

# TODO integration tests:

# set position
# "AZ%.1f EL%.1f UP000 XXX DN000 XXX\n
# "AZ%.1f EL%.1f

# get position
# AZ EL -> AZf ELf

# movement stop
# "SA SE

# rotor park
# PARK

# rotor move
# MU MD ML MR

# move velocity 0 - 100 vs 0 - 9999
# "VU%04d\ vd vr fl

#get registers
# GS GE IP AM VE CR
