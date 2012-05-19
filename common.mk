MCU   ?= atmega8
F_CPU ?= 1000000
FORMAT ?= ihex
# Target file name (without extension).
ifndef TARGET
$(error TARGET must be defined)
endif
DEBUG ?= 0
OPT ?= s
ifndef AVR_COMMON_API
$(warning AVR_COMMON_API is undefined)
AVR_COMMON_API = 1
endif

CFLAGS += -DAVR_COMMON_API=$(AVR_COMMON_API)

ifeq ($(DEBUG), 1)
SRC += common/debug.c
CFLAGS += -DDEBUG
else
CFLAGS += -DNDEBUG
endif

ifdef WITH_UART
SRC += common/uart.c
CFLAGS += -DWITH_UART
endif

ifdef WITH_RAND
SRC += common/rand.c
CFLAGS += -DWITH_RAND
endif

ifdef WITH_LCD
SRC += common/lcd.c
CFLAGS += -DWITH_LCD
endif

CFLAGS += -g -O$(OPT) \
-funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums \
-W -Wall -Wextra -Wstrict-prototypes -Werror \
-DF_CPU=$(F_CPU) \
-Wa,-adhlns=$(<:.c=.lst) \
-std=gnu99 \
$(patsubst %,-I%,$(INCLUDES))

LDFLAGS += -Wl,-Map=$(TARGET).map,--cref

AVRDUDE_WRITE_FLASH  ?= -U flash:w:$(TARGET).hex
AVRDUDE_WRITE_EEPROM ?= -U eeprom:w:$(TARGET).eep

AVRDUDE_FLAGS += -p $(MCU)

TOOLCHAIN=avr-

CC = $(TOOLCHAIN)gcc

OBJCOPY = $(TOOLCHAIN)objcopy
OBJDUMP = $(TOOLCHAIN)objdump
SIZE = $(TOOLCHAIN)size

AVRDUDE = avrdude

RM = rm -f

HEXSIZE = $(SIZE) --target=$(FORMAT) $(TARGET).hex
ELFSIZE = $(SIZE) -A $(TARGET).elf

OBJ = $(SRC:.c=.o) $(ASRC:.S=.o)

ALL_CFLAGS = -mmcu=$(MCU) -I. $(CFLAGS)

.PHONY: all
all:  $(TARGET).elf $(TARGET).hex $(TARGET).eep $(TARGET).lss $(TARGET).sym sizeafter

.PHONY: sizeafter
sizeafter:
	$(ELFSIZE)

.PHONY: reset
reset:
	$(AVRDUDE) $(AVRDUDE_FLAGS)

.PHONY: program
program: $(TARGET).hex $(TARGET).eep
	$(AVRDUDE) $(AVRDUDE_FLAGS) $(AVRDUDE_WRITE_FLASH) # $(AVRDUDE_WRITE_EEPROM)

.PHONY: full
full: $(TARGET).hex program

burn-fuse:
	$(AVRDUDE) $(AVRDUDE_FLAGS) -B 250 -u -U lfuse:w:0xfd:m -U hfuse:w:0xdf:m

read-fuse:
	$(AVRDUDE) $(AVRDUDE_FLAGS) -u -U lfuse:r:l.txt:r
	$(AVRDUDE) $(AVRDUDE_FLAGS) -u -U hfuse:r:h.txt:r
	$(AVRDUDE) $(AVRDUDE_FLAGS) -u -U efuse:r:e.txt:r

%.hex: %.elf
	$(OBJCOPY) -O $(FORMAT) -R .eeprom $< $@

%.eep: %.elf
	-$(OBJCOPY) -j .eeprom --set-section-flags=.eeprom="alloc,load" --change-section-lma .eeprom=0 -O $(FORMAT) $< $@

%.lss: %.elf
	$(OBJDUMP) -h -S $< > $@

%.sym: %.elf
	avr-nm -n $< > $@

.SECONDARY: $(TARGET).elf
.PRECIOUS: $(OBJ)
%.elf: $(OBJ)
	$(CC) $(ALL_CFLAGS) $(OBJ) -o $@ $(LDFLAGS)

%.o : %.c Makefile
	$(CC) -c $(ALL_CFLAGS) $< -o $@

%.d: %.c
	$(CC) $(ALL_CFLAGS) -M -MD -MP -MT $(<:.c=.o) -o $@ $<
-include $(SRC:.c=.d)

%.E: %.c
	$(CC) -E $(ALL_CFLAGS) -o $@ $<

clean:
	$(RM) $(TARGET).hex $(TARGET).eep $(TARGET).obj $(TARGET).cof $(TARGET).elf $(TARGET).map $(TARGET).obj $(TARGET).a90 $(TARGET).sym $(TARGET).lnk $(TARGET).lss $(OBJ) $(SRC:.c=.lst) $(SRC:.c=.s) $(SRC:.c=.d) $(SRC:.c=.E)
