APPNAME = netclient2
SRC = src/main.cpp

include ../Makefile.config

APPOBJ_ = $(subst src,build,$(SRC))
APPOBJ__ = $(APPOBJ_:.c=.o)
APPOBJ = $(APPOBJ__:.cpp=.o)

LIBRARY_PATH += -L$(MBED_SDK_PATH)/net/eth/TARGET_LPC1768/TOOLCHAIN_GCC_ARM/
LIBRARIES = -leth -lrtx -lrtos -lmbed -lstdc++ -lsupc++ -lm -lc -lgcc -lnosys

INCLUDE += \
-I$(MBED_SDK_PATH)/net/eth/EthernetInterface/ \
-I$(MBED_SDK_PATH)/net/eth/ \
-I$(MBED_SDK_PATH)/net/eth/Socket \
-I$(MBED_SDK_PATH)/net/eth/lwip/ \
-I$(MBED_SDK_PATH)/net/eth/lwip-eth/arch/TARGET_NXP/ \
-I$(MBED_SDK_PATH)/net/eth/lwip-sys/ \
-I$(MBED_SDK_PATH)/mbed/TARGET_$(TARGET)/TOOLCHAIN_$(TOOLCHAIN) \
-I $(MBED_SDK_PATH)/rtos/

#-I TextLCD \

all: __INIT__ bin/$(APPNAME).bin

__INIT__:
	mkdir -p bin build

bin/$(APPNAME).bin: build/$(APPNAME).elf
	$(OBJCOPY) -O binary $< $@

build/$(APPNAME).elf: $(APPOBJ)
	$(CC) $(LDOPT) $(LDOBJ) $? $(LIBRARIES) $(LIBRARY_PATH) -o $@

build/%.o: src/%.cpp
	echo $<
	$(CC) $(INCLUDE) $(CCOPT) $< -o $@

build/%.o: src/%.c
	$(CC) $(INCLUDE) $(COPT) $< -o $@

install: bin/$(APPNAME).bin
	cp bin/$(APPNAME).bin $(MBEDPATH)

clean:
	rm -rf bin build *~
