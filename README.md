===============================================================================
mbed_app: mbed sample app built by make
===============================================================================

How to build mbed SDK (on Ubuntu)
---------------------------------
0. Install 32bit libc
   sudo apt-get install libc6-dev-i386
1. Install GNU Tools for ARM Embedded Processors
  https://launchpad.net/gcc-arm-embedded/4.7/4.7-2012-q4-major
  Installed location is TOOLCHAIN_PATH
2. Clone mbed libraries and build tools: [Detail](https://github.com/mbedmicro/mbed/blob/master/docs/BUILDING.md)
    git clone https://github.com/mbedmicro/mbed.git
3. Apply patch to patch.py
    cd mbed
    patch -p1 < ../python-tools.patch
4. Create workspace_tools/private_settings.py from workspace_tools/setting.py
5. Build mbed using build.py. e.g. Build all libraries for LPC1768
    python workspace_tools/build.py -m LPC1768 -t GCC_ARM -r -e -u -d
  A directory named build created as result which contains headers and libraries.

Directry tree
-------------
 + mbed
 +- build: mbed headers and libs (MBED_SDK_PATH in Makefile.config)
 + Makefile.config: common makefile settings
 |
 + hello_app: led app
 + netclient2: network client app

How to try mbed app
-------------------
1. Connect mbed device to PC using usb cable
2. edit Makefile.config to modify MBED_PATH TARGET TOPDIR MBED_SDK_PATH TOOLCHAIN_PATH 
3. cd hello_app
4. make
5. make install
6. In case of linux
    sudo screen /dev/ttyACM0 9600
7. Push reset button of mbed
8. "Hello mbed" will be printed to screen and LED1 and LED2 will blink.

App projects
------------
* hello_app
 printf and led, only depend on mbed
* hello_led_app
 use TextLCD library, target is StarBoard Orange
 http://mbed.org/users/simon/code/TextLCD/

Files in app project
--------------------
Makefile
bin: final .bin file is located
build: .o, elf files are located
src: source code

MBED_SDK: mbed sdk built with workspace_tools/build.py
TOOLCHAIN_PATH: arm compiler available from the following web page
  https://launchpad.net/gcc-arm-embedded/4.7/4.7-2012-q4-major

TODO
-----------
* ethernet sample, USB sample
* create starbord orange library
   * some libraries are contained in mbed (SD, FATFileSystem ...)
* create more sophisticated Makefile
   * make subdir under build directory automatically
* build SDFileSystem, FAT using build.py

Reference
---------
* http://mbed.org/handbook/mbed-tools
* [mbed LPC1768](https://developer.mbed.org/platforms/mbed-LPC1768/)
* [StarBoard Orange](http://mbed.org/cookbook/StarBoard-Orange)

----
Takashi Masuyama < mamewotoko@gmail.com >  
http://www002.upp.so-net.ne.jp/mamewo/
