APPNAME = orange_sd
#TODO: replace
SRC=src/main.cpp

include ../Makefile.config

INCLUDE += -Ilib/textlcd -Ilib/fs/sd -Ilib/fs/fat -Ilib/fs/fat/ChaN

LIBRARY_PATH = -L$(MBED_SDK_PATH)/mbed/TARGET_$(TARGET)/TOOLCHAIN_$(TOOLCHAIN)
LIBRARIES = -lmbed -lstdc++ -lsupc++ -lm -lc -lgcc -lnosys

LIBSRC = lib/fs/sd/SDFileSystem.cpp \
lib/fs/fat/FATFileHandle.cpp \
lib/fs/fat/FATFileSystem.cpp \
lib/fs/fat/FATDirHandle.cpp \
lib/fs/fat/ChaN/ff.cpp \
lib/fs/fat/ChaN/ccsbcs.cpp \
lib/fs/fat/ChaN/diskio.cpp \
lib/textlcd/TextLCD.cpp 

APPOBJ_ = $(SRC:.cpp=.o)
APPOBJ = $(subst src/,build/,$(APPOBJ_))

LIBOBJ_ = $(LIBSRC:.cpp=.o)
LIBOBJ = $(subst lib/,build/,$(LIBOBJ_))

all: __INIT__ bin/$(APPNAME).bin

__INIT__:
	mkdir -p bin build build/textlcd build/fs/fat build/fs/fat/ChaN build/fs/sd

bin/$(APPNAME).bin: build/$(APPNAME).elf
	$(OBJCOPY) -O binary $< $@

build/$(APPNAME).elf: $(APPOBJ) $(LIBOBJ)
	$(CC) $(LDOPT) $(LDOBJ) $(APPOBJ) $(LIBOBJ) $(LIBRARIES) $(LIBRARY_PATH) -o $@

## ummm: create library

build/%.o: src/%.cpp
	$(CC) $(INCLUDE) $(CCOPT) $< -o $@

build/%.o: lib/%.cpp
	$(CC) $(INCLUDE) $(CCOPT) $< -o $@

install: bin/$(APPNAME).bin
	cp bin/$(APPNAME).bin $(MBEDPATH)

clean:
	rm -rf bin build *~
