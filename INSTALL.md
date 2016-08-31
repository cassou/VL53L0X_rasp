# VL53L0X on Raspberry Pi

This project helps to build and use the VL53L0X API (provided by ST Microelectronics) on Raspberry Pi.

### Installation

* Download the sources of the api on the ST Microelectronics, they are not provided in this repo (I didn't read their license yet, I do not want get in trouble by distributing their code). http://www.st.com/content/st_com/en/products/embedded-software/proximity-sensors-software/stsw-img005.html

* Extract the API source code somewhere on your computer.
* You will only need the Api subfolder and its content. The makefile expects the folder structure to be:
```
API_DIR
    |_Api
        |_core
            |_inc
            |_src
        |_platform
            |_inc
            |_src
```

### Compilation

* If your are cross compiling on another platform, follow "INSTALL THE TOOLCHAIN" before attempting to compile here: https://www.raspberrypi.org/documentation/linux/kernel/building.md

* To compile the lib directly on your raspberry pi:
```bash
API_DIR=path/to/the/api/dir make
```

* If you are cross compiling it would be:
```bash
API_DIR=path/to/the/api/dir CROSS_COMPILE=arm-linux-gnueabihf- make
```

* Next, compile the example programs. Again, on a raspberry pi:
```bash
API_DIR=path/to/the/api/dir make examples
```

* If you cross compile:
```bash
API_DIR=path/to/the/api/dir CROSS_COMPILE=arm-linux-gnueabihf- make examples
```

* If you did cross compile, copy the examples programs from the bin folder to your Raspberry Pi. Otherwise just navigate to the bin folder on your raspberry pi and execute:
```
./vl53l0x_ContinuousRanging_example
```
or
```
./vl53l0x_SingleRanging_Long_Range_Example
```

* run the one of the example programs and enjoy!

Note : I know there are kernel driver sources in the API sources, I don't want to use it because it is easier to compil/debug/test/install... a userspace program than a kernel module (high perf is not necessary here).

![alt text](https://github.com/cassou/VL53L0X_rasp/blob/master/doc/raspi_bb.png "hookup example")


