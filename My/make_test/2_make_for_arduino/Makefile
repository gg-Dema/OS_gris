CC=avr-gcc
INCLUDE_DIRS= -I. -I../../c_code/arduino/avr_common
CC_OPTS= -Wall --std=gnu99 -DF_CPU=16000000UL -funsigned-char -mmcu=atmega2560 -D__AVR_3_BYTE_PC__

BINS=test.elf
OBJS=../../c_code/arduino/avr_common/uart.o 
HEADERS=../../c_code/arduino/avr_common/uart.h


AVRDUDE=avrdude 
AVRDUDE_PORT=/dev/ttyACM0

#normal storage for program (flash)
AVRDUDE_WRITE_FLASH= -U flash:w:$(TARGET):i
AVRDUDE_FLAGS= -p m2560 -P $(AVRDUDE_PORT) -c $(AVRDUDE_PROGRAMMER) -b 19600
AVRDUDE_FLAGS+= -D -q -V -C /usr/share/arduino/hardware/tools/avr/../avrdude.conf
AVRDUDE_FLAGS += -c wiring


.phony:	clean all

all:	$(BINS)

#common objects
%.o:	%.c
		$(CC) $(CC_OPTS) -c -o $@ $<

%.elf:	%.o $(OBJS) #  OBJS and LIBS sono passati da un altro MakeFile
		$(CC) $(CC_OPTS) -o $@ $< $(OBJS) $(LIBS)

# avr-objcopy traduce elf in hex (elf non è eseguibile 
%.hex:	%.elf
		avr-objcopy -O ihex -R .eeprom $< $@ 
		$(AVRDUDE) $(AVRDUDE_FLAGS) -U flash:w:$@:i 
		
clean: 
	rm -rf $(OBJS) $(BINS) *.hex *~ *.o 

.SECONDARY:	$(OBJS)