#VL53L0X on Raspberry Pi

This is a work in progress.

The goal is to get the VL53L0X API provided by ST Microelectronics to work on Raspberry Pi.

Note : I know there is kernel driver provided in the API sources, I don't want to use it because it will be easier (for me) to debug and understand a userspace lib.

* Download the sources of the api on the ST Microelectronics, they are not provided in this repo (I didn't read their license yet, i do not want get in trouble by distributing their code).
* Extract the API source code somewhere on your device.
* If your are cross compiling, follow "INSTALL THE TOOLCHAIN" here: https://www.raspberrypi.org/documentation/linux/kernel/building.md
* Run 'API_DIR=path/to/the/api/dir CROSS_COMPILE=arm-linux-gnueabihf- make'