APPNAME = orange_sd
#TODO: replace
APPOBJ =  build/main.o
MBEDPATH = /media/tak/MBED
APP_INCLUDE = -Ilib/textlcd -Ilib/fs/sd -Ilib/fs/fat -Ilib/fs/fat/ChaN

TOPDIR = /home/tak/dev/mbed/
MBED_SDK_PATH = $(TOPDIR)/build
PATCHAPP = $(TOPDIR)/mbed/workspace_tools/patch.py
TOOLCHAIN_PATH = /home/tak/dev/mbed/toolchain/gcc-arm-none-eabi-4_7-2012q4/bin/
TARGET = LPC1768
TOOLCHAIN = GCC_ARM

TOOLCHAIN_PREFIX = arm-none-eabi-
CC = $(TOOLCHAIN_PATH)/$(TOOLCHAIN_PREFIX)gcc
CPP = $(TOOLCHAIN_PATH)/$(TOOLCHAIN_PREFIX)g++
OBJCOPY = $(TOOLCHAIN_PATH)/$(TOOLCHAIN_PREFIX)objcopy
LIBPATY_PATH = -L$(MBED_SDK_PATH)/mbed/TARGET_$(TARGET)/TOOLCHAIN_$(TOOLCHAIN)
LIBRARIES = -lmbed -lstdc++ -lsupc++ -lm -lc -lgcc \
-lnosys -lmbed -lstdc++ -lsupc++ -lm -lc -lgcc -lnosys

INCLUDE = -I$(MBED_SDK_PATH)/mbed \
-I$(MBED_SDK_PATH)/mbed/libraries/fs/sd \
-I$(MBED_SDK_PATH)/mbed/TARGET_$(TARGET) \
-I$(MBED_SDK_PATH)/mbed/TARGET_$(TARGET)/TOOLCHAIN_$(TOOLCHAIN) \
$(APP_INCLUDE)

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

LIBSRC = lib/fs/sd/SDFileSystem.cpp \
lib/fs/fat/FATFileHandle.cpp \
lib/fs/fat/FATFileSystem.cpp \
lib/fs/fat/FATDirHandle.cpp \
lib/fs/fat/ChaN/ff.cpp \
lib/fs/fat/ChaN/ccsbcs.cpp \
lib/fs/fat/ChaN/diskio.cpp \
lib/textlcd/TextLCD.cpp 

LIBOBJ_ = $(LIBSRC:.cpp=.o)
LIBOBJ = $(subst lib/,build/,$(LIBOBJ_))

all: __INIT__ bin/$(APPNAME).bin

__INIT__:
	mkdir -p bin build build/textlcd build/fs/fat build/fs/fat/ChaN build/fs/sd

bin/$(APPNAME).bin: build/$(APPNAME).elf
	$(OBJCOPY) -O binary $< $@
	python $(PATCHAPP) $@

build/$(APPNAME).elf: $(APPOBJ) $(LIBOBJ)
	$(CC) $(LDOPT) $(LDOBJ) $? $(LIBRARIES) $(LIBPATY_PATH) -o $@

## ummm: create library

build/%.o: src/%.cpp
	$(CC) $(INCLUDE) $(CCOPT) -c $< -o $@

build/%.o: lib/%.cpp
	$(CC) $(INCLUDE) $(CCOPT) -c $< -o $@

install: bin/$(APPNAME).bin
	cp bin/$(APPNAME).bin $(MBEDPATH)

clean:
	rm -rf bin build *~
