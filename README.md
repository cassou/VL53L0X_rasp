# VL53L0X on Raspberry Pi

This project help to build and use the VL53L0X API (provided by ST Microelectronics) on Raspberry Pi.

### Installation

* Download the sources of the api on the ST Microelectronics, they are not provided in this repo (I didn't read their license yet, I do not want get in trouble by distributing their code). http://www.st.com/content/st_com/en/products/embedded-software/proximity-sensors-software/stsw-img005.html
* Extract the API source code somewhere on your computer.

### Compilation

* If your are cross compiling, follow "INSTALL THE TOOLCHAIN" here: https://www.raspberrypi.org/documentation/linux/kernel/building.md

* Compil the lib :
```bash
API_DIR=path/to/the/api/dir CROSS_COMPILE=arm-linux-gnueabihf- make
```

* Compil the example program :

```bash
API_DIR=path/to/the/api/dir CROSS_COMPILE=arm-linux-gnueabihf- make test
```

* Copy the 'test' file on your Raspberry Pi
* launch the 'test' program and your are done !


Note : I know there are kernel driver sources in the API sources, I don't want to use it because it is easier to compil/debug/test/install... a userspace program than a kernel module (high perf is not necessary here).

![alt text](https://github.com/cassou/VL53L0X_rasp/blob/master/doc/raspi_bb.png "cabling example")
