###############################################################################
# Makefile for the project LM35_ATMEGA_LABVIEW_TX
###############################################################################

## General Flags
PROJECT = LM35_ATMEGA_LABVIEW_TX
MCU = atmega16
TARGET = LM35_ATMEGA_LABVIEW_TX.elf
CC = avr-gcc

## Options common to compile, link and assembly rules
COMMON = -mmcu=$(MCU)

## Compile options common for all C compilation units.
CFLAGS = $(COMMON)
CFLAGS += -Wall -gdwarf-2 -Os -std=gnu99 -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
CFLAGS += -MD -MP -MT $(*F).o -MF dep/$(@F).d 

## Assembly specific flags
ASMFLAGS = $(COMMON)
ASMFLAGS += $(CFLAGS)
ASMFLAGS += -x assembler-with-cpp -Wa,-gdwarf2

## Linker flags
LDFLAGS = $(COMMON)
LDFLAGS +=  -Wl,-Map=LM35_ATMEGA_LABVIEW_TX.map


## Intel Hex file production flags
HEX_FLASH_FLAGS = -R .eeprom -R .fuse -R .lock -R .signature

HEX_EEPROM_FLAGS = -j .eeprom
HEX_EEPROM_FLAGS += --set-section-flags=.eeprom="alloc,load"
HEX_EEPROM_FLAGS += --change-section-lma .eeprom=0 --no-change-warnings


## Objects that must be built in order to link
OBJECTS = LM35_ATMEGA_LABVIEW_TX.o adc.o lcd.o usart_lib.o 

## Objects explicitly added by the user
LINKONLYOBJECTS = 

## Build
all: $(TARGET) LM35_ATMEGA_LABVIEW_TX.hex LM35_ATMEGA_LABVIEW_TX.eep LM35_ATMEGA_LABVIEW_TX.lss size

## Compile
LM35_ATMEGA_LABVIEW_TX.o: ../LM35_ATMEGA_LABVIEW_TX.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

adc.o: ../adc.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

lcd.o: ../lcd.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

usart_lib.o: ../usart_lib.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

##Link
$(TARGET): $(OBJECTS)
	 $(CC) $(LDFLAGS) $(OBJECTS) $(LINKONLYOBJECTS) $(LIBDIRS) $(LIBS) -o $(TARGET)

%.hex: $(TARGET)
	avr-objcopy -O ihex $(HEX_FLASH_FLAGS)  $< $@

%.eep: $(TARGET)
	-avr-objcopy $(HEX_EEPROM_FLAGS) -O ihex $< $@ || exit 0

%.lss: $(TARGET)
	avr-objdump -h -S $< > $@

size: ${TARGET}
	@echo
	@avr-size -C --mcu=${MCU} ${TARGET}

## Clean target
.PHONY: clean
clean:
	-rm -rf $(OBJECTS) LM35_ATMEGA_LABVIEW_TX.elf dep/* LM35_ATMEGA_LABVIEW_TX.hex LM35_ATMEGA_LABVIEW_TX.eep LM35_ATMEGA_LABVIEW_TX.lss LM35_ATMEGA_LABVIEW_TX.map


## Other dependencies
-include $(shell mkdir dep 2>/dev/null) $(wildcard dep/*)

