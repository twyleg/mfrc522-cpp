# mfrc522-cpp

Library for the popular MFRC522 RFID card reader/writer. It was forked from [paguz/RPi-RFID](https://github.com/paguz/RPi-RFID) to add support for spidev and cmake.

## Prerequisites

This if you want to use apps/bcm2835_read_example/ you have to build the [bcm2835 library ](http://www.airspayce.com/mikem/bcm2835/bcm2835-1.50.tar.gz) first:

Fetch the tar-file and install it:

	 tar zxvf bcm2835-1.xx.tar.gz

Build:
  
 	cd bcm2835-1.xx
	./configure
	make

Install:
	
	sudo make check
	sudo make install


## Build

Clone:

	git clone https://github.com/twyleg/mfrc522-cpp
	
Create build directory:

	cd mfrc522-cpp/
	mkdir build
	
Build:

	cmake ../
	make

## Examples

The project provices two examples:

- apps/spidev_read_example
- apps/bcm2835_read_example

That use spidev or the bcm2835 library to access the SPI interface.

**Note:** Be aware that bcm2835 requires root priviliges and that running the spidev example after the bcm2835 example might fail (read the Troubleshooting section of the [spidevpp README.md](https://github.com/twyleg/spidevpp/blob/master/README.md) for further infos.

