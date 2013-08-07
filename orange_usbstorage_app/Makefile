APPNAME = orange_usbstorage
#TODO: replace
APPOBJ =  build/main.o
MBEDPATH = /media/tak/MBED

TOPDIR = /home/tak/dev/mbed/
MBED_SDK_PATH = $(TOPDIR)/build
PATCHAPP = $(TOPDIR)/mbed/workspace_tools/patch.py
TOOLCHAIN_PATH = /home/tak/dev/mbed/toolchain/gcc-arm-none-eabi-4_7-2012q4/bin/
TARGET = LPC1768
TOOLCHAIN = GCC_ARM

TOOLCHAIN_PREFIX = arm-none-eabi
CC = $(TOOLCHAIN_PATH)/$(TOOLCHAIN_PREFIX)-gcc
CPP = $(TOOLCHAIN_PATH)/$(TOOLCHAIN_PREFIX)-g++
OBJCOPY = $(TOOLCHAIN_PATH)/$(TOOLCHAIN_PREFIX)-objcopy
LD = $(TOOLCHAIN_PATH)/$(TOOLCHAIN_PREFIX)-ld

LIBPATY_PATH = -L$(MBED_SDK_PATH)/mbed/TARGET_$(TARGET)/TOOLCHAIN_$(TOOLCHAIN)
LIBRARIES = -lmbed -lstdc++ -lsupc++ -lm -lc -lgcc \
-lnosys -lmbed -lstdc++ -lsupc++ -lm -lc -lgcc -lnosys

INCLUDE = -I$(MBED_SDK_PATH)/mbed \
-I$(MBED_SDK_PATH)/mbed/TARGET_$(TARGET) \
-I$(MBED_SDK_PATH)/mbed/TARGET_$(TARGET)/TOOLCHAIN_$(TOOLCHAIN) \
-Ilib/textlcd/ \
-Ilib/fs/MSCFileSystem/USBHostLite/ \
-Ilib/fs/MSCFileSystem/ \
-Ilib/fs/FATFileSystem/ChaN/ \
-Ilib/fs/FATFileSystem/

ARCHOPT = -mcpu=cortex-m3 -mthumb

CCOPT = $(ARCHOPT) -std=gnu++98 -c -O2 -Wall -fmessage-length=0 -fno-exceptions \
-fno-builtin -ffunction-sections -fdata-sections -MMD \
-DTARGET_LPC1768 -DTARGET_M3 -DTARGET_NXP -DTARGET_LPC176X \
-DTOOLCHAIN_GCC_ARM -DTOOLCHAIN_GCC -D__CORTEX_M3 -DARM_MATH_CM3

LDOPT = $(ARCHOPT) -Wl,--gc-sections --specs=nano.specs \
-T$(MBED_SDK_PATH)/mbed/TARGET_$(TARGET)/TOOLCHAIN_$(TOOLCHAIN)/LPC1768.ld

LDOBJ = $(MBED_SDK_PATH)/mbed/TARGET_$(TARGET)/TOOLCHAIN_$(TOOLCHAIN)/system_LPC17xx.o \
$(MBED_SDK_PATH)/mbed/TARGET_$(TARGET)/TOOLCHAIN_$(TOOLCHAIN)/cmsis_nvic.o \
$(MBED_SDK_PATH)/mbed/TARGET_$(TARGET)/TOOLCHAIN_$(TOOLCHAIN)/startup_LPC17xx.o \
$(MBED_SDK_PATH)/mbed/TARGET_$(TARGET)/TOOLCHAIN_$(TOOLCHAIN)/retarget.o

LIBSRC = lib/textlcd/TextLCD.cpp \
lib/fs/MSCFileSystem/USBHostLite/usbhost_ms.cpp \
lib/fs/MSCFileSystem/USBHostLite/usbhost_lpc17xx.cpp \
lib/fs/MSCFileSystem/MSCFileSystem.cpp \
lib/fs/FATFileSystem/FATFileHandle.cpp \
lib/fs/FATFileSystem/FATFileSystem.cpp \
lib/fs/FATFileSystem/FATDirHandle.cpp \
lib/fs/FATFileSystem/ChaN/ff.cpp \
lib/fs/FATFileSystem/ChaN/ccsbcs.cpp \
lib/fs/FATFileSystem/ChaN/diskio.cpp

LIBOBJ_ = $(LIBSRC:.cpp=.o)
LIBOBJ__ = $(LIBOBJ_:.c=.o)
LIBOBJ = $(subst lib/,build/,$(LIBOBJ__))

all: __INIT__ bin/$(APPNAME).bin

__INIT__:
	mkdir -p bin build build/textlcd build/fs/FATFileSystem/ChaN build/fs/MSCFileSystem/USBHostLite

bin/$(APPNAME).bin: build/$(APPNAME).elf
	$(OBJCOPY) -O binary $< $@
	python $(PATCHAPP) $@

build/$(APPNAME).elf: $(APPOBJ) $(LIBOBJ)
	$(CC) $(LDOPT) $(LDOBJ) $(APPOBJ) $(LIBOBJ) $(LIBRARIES) $(LIBPATY_PATH) -o $@

## ummm: create library
build/%.o: src/%.cpp
	$(CC) $(INCLUDE) $(CCOPT) -c $< -o $@

build/%.o: lib/%.cpp
	$(CC) -E $(INCLUDE) $(CCOPT) $< -o $@

build/%.o: lib/%.c
	$(CPP) $(INCLUDE) $(CCOPT) -c $< -o $@

install: bin/$(APPNAME).bin
	cp bin/$(APPNAME).bin $(MBEDPATH)

clean:
	rm -rf bin build *~
