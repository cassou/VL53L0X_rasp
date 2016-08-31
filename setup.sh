#!/bin/bash

check=$(i2cdetect -y 1 | grep "28")

if [ "${check}" = "" ]; then

	echo 4 > /sys/class/gpio/export
	echo out > /sys/class/gpio/gpio4/direction
	echo 0 > /sys/class/gpio/gpio4/value

	bin/setup

	echo 1 > /sys/class/gpio/gpio4/value

fi

i2cdetect -y 1

bin/test 0x29
bin/test 0x28
