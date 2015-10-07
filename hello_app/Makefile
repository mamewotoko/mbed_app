APPNAME = hello
SRC = src/main.cpp

MBEDPATH = /media/tak/MBED
TARGET = LPC1768
TOPDIR = $(PWD)/../
MBED_SDK_PATH = $(TOPDIR)/build
PATCHAPP = $(TOPDIR)/mbed/workspace_tools/patch.py
TOOLCHAIN_PATH = /home/tak/dev/mbed/toolchain/gcc-arm-none-eabi-4_7-2012q4/bin/

TOOLCHAIN = GCC_ARM
TOOLCHAIN_PREFIX = arm-none-eabi

CC = $(TOOLCHAIN_PATH)/$(TOOLCHAIN_PREFIX)-gcc
CPP = $(TOOLCHAIN_PATH)/$(TOOLCHAIN_PREFIX)-g++
OBJCOPY = $(TOOLCHAIN_PATH)/$(TOOLCHAIN_PREFIX)-objcopy
AR = $(TOOLCHAIN_PATH)/$(TOOLCHAIN_PREFIX)-ar

LIBPATY_PATH = -L$(MBED_SDK_PATH)/mbed/TARGET_$(TARGET)/TOOLCHAIN_$(TOOLCHAIN)
LIBRARIES = -lmbed -lstdc++ -lsupc++ -lm -lc -lgcc \
-lnosys -lmbed -lstdc++ -lsupc++ -lm -lc -lgcc -lnosys

INCLUDE = -I$(MBED_SDK_PATH)/mbed \
-I$(MBED_SDK_PATH)/mbed/TARGET_$(TARGET) \
-I$(MBED_SDK_PATH)/mbed/TARGET_$(TARGET)/TOOLCHAIN_$(TOOLCHAIN)

ARCHOPT = -mcpu=cortex-m3 -mthumb

BASEOPT =  $(ARCHOPT) -c -O2 -Wall -fmessage-length=0 -fno-exceptions \
-fno-builtin -ffunction-sections -fdata-sections -MMD \
-DTARGET_LPC1768 -DTARGET_M3 -DTARGET_NXP -DTARGET_LPC176X \
-DTOOLCHAIN_GCC_ARM -DTOOLCHAIN_GCC -D__CORTEX_M3 -DARM_MATH_CM3

CPPOPT = -std=gnu++98 $(BASEOPT)
COPT = -std=gnu99 $(BASEOPT)

LDOPT = $(ARCHOPT) -Wl,--gc-sections --specs=nano.specs \
-T$(MBED_SDK_PATH)/mbed/TARGET_$(TARGET)/TOOLCHAIN_$(TOOLCHAIN)/LPC1768.ld

LDOBJ = $(MBED_SDK_PATH)/mbed/TARGET_$(TARGET)/TOOLCHAIN_$(TOOLCHAIN)/system_LPC17xx.o \
$(MBED_SDK_PATH)/mbed/TARGET_$(TARGET)/TOOLCHAIN_$(TOOLCHAIN)/cmsis_nvic.o \
$(MBED_SDK_PATH)/mbed/TARGET_$(TARGET)/TOOLCHAIN_$(TOOLCHAIN)/startup_LPC17xx.o \
$(MBED_SDK_PATH)/mbed/TARGET_$(TARGET)/TOOLCHAIN_$(TOOLCHAIN)/retarget.o

APPOBJ_ = $(subst src,build,$(SRC))
APPOBJ__ = $(APPOBJ_:.c=.o)
APPOBJ = $(APPOBJ__:.cpp=.o)

all: bin build bin/$(APPNAME).bin

bin build:
	mkdir $@

bin/$(APPNAME).bin: build/$(APPNAME).elf
	$(OBJCOPY) -O binary $< $@
	python $(PATCHAPP) $@

build/$(APPNAME).elf: $(APPOBJ)
	$(CC) $(LDOPT) $(LDOBJ) $? $(LIBRARIES) $(LIBPATY_PATH) -o $@

build/%.o: src/%.cpp
	$(CC) $(INCLUDE) $(CPPOPT) -c $< -o $@

build/%.o: src/%.c
	$(CC) $(INCLUDE) $(COPT) -c $< -o $@

install: bin/$(APPNAME).bin
	cp bin/$(APPNAME).bin $(MBEDPATH)

clean:
	rm -rf bin build *~
