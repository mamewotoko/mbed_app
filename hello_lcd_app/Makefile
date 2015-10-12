APPNAME = hello_lcd
#TODO: replace
APPOBJ =  build/TextLCD.o build/main.o

include ../Makefile.config

INCLUDE += -Ilib/textlcd

#LIBRARIES = -lmbed -lstdc++ -lsupc++ -lm -lc -lgcc -lnosys

all: bin build bin/$(APPNAME).bin

bin/$(APPNAME).bin: build/$(APPNAME).elf
	$(OBJCOPY) -O binary $< $@

bin build:
	mkdir $@

build/$(APPNAME).elf: $(APPOBJ)
	$(CC) $(LDOPT) $(LIBRARY_PATH) $? $(LDOBJ) $(LIBRARIES) -o $@

## ummm: create library
build/TextLCD.o: lib/textlcd/TextLCD.cpp
	$(CC) $(INCLUDE) $(CCOPT) $< -o $@

build/%.o: src/%.cpp
	$(CC) $(INCLUDE) $(CCOPT) $< -o $@

install: bin/$(APPNAME).bin
	cp bin/$(APPNAME).bin $(MBEDPATH)

clean:
	rm -rf bin build *~
