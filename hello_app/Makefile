APPNAME = hello
#TODO: replace
APPOBJ = build/main.o
MBEDPATH = /media/tak/MBED


TOPDIR = /home/tak/dev/mbed/
MBED_SDK_PATH = $(TOPDIR)/build
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
-I$(MBED_SDK_PATH)/mbed/TARGET_$(TARGET) \
-I$(MBED_SDK_PATH)/mbed/TARGET_$(TARGET)/TOOLCHAIN_$(TOOLCHAIN)

ARCHOPT = -mcpu=cortex-m3 -mthumb

CCOPT = $(ARCHOPT) -std=gnu++98 -c -O2 -Wall -fmessage-length=0 -fno-exceptions \
-fno-builtin -ffunction-sections -fdata-sections -MMD \
-DTARGET_LPC1768 -DTARGET_M3 -DTARGET_NXP -DTARGET_LPC176X \
-DTOOLCHAIN_GCC_ARM -DTOOLCHAIN_GCC -D__CORTEX_M3 -DARM_MATH_CM3

LDOPT = -Wl,--gc-sections --specs=nano.specs \
-T$(MBED_SDK_PATH)/mbed/TARGET_$(TARGET)/TOOLCHAIN_$(TOOLCHAIN)/LPC1768.ld

LDOBJ = $(MBED_SDK_PATH)/mbed/TARGET_$(TARGET)/TOOLCHAIN_$(TOOLCHAIN)/system_LPC17xx.o \
$(MBED_SDK_PATH)/mbed/TARGET_$(TARGET)/TOOLCHAIN_$(TOOLCHAIN)/cmsis_nvic.o \
$(MBED_SDK_PATH)/mbed/TARGET_$(TARGET)/TOOLCHAIN_$(TOOLCHAIN)/startup_LPC17xx.o \
$(MBED_SDK_PATH)/mbed/TARGET_$(TARGET)/TOOLCHAIN_$(TOOLCHAIN)/retarget.o

all: bin build bin/$(APPNAME).bin

bin/$(APPNAME).bin: build/$(APPNAME).elf
	$(OBJCOPY) -O binary $< $@
	python $(TOPDIR)/mbed/workspace_tools/patch.py $@

bin build:
	mkdir $@

build/$(APPNAME).elf: $(APPOBJ)
	$(CC) $(LDOPT) $(LDOBJ) $? $(LIBRARIES) $(LIBPATY_PATH) -o $@

build/%.o: src/%.cpp
	$(CC) $(INCLUDE) $(CCOPT) -c $< -o $@

run:
	cp bin/$(APPNAME).bin $(MBEDPATH)

clean:
	rm -rf bin build *~
