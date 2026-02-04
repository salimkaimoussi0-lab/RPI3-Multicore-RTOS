#===============================================================
# FOLDERS
#===============================================================
CWD        = $(shell pwd)
# Base folder for include paths
INCLUDEDIR = $(dir $(CWD))
# All library sources are currently there
LIBDIR     = $(INCLUDEDIR)/librpi3

#####################################################
# SOURCES
#####################################################

ASMFILES = \
	$(wildcard $(LIBDIR)/*.S)

CFILES = \
	$(wildcard $(LIBDIR)/*.c) \
	loader.c \
	main.c

HEADERS = \
	$(wildcard $(LIBDIR)/*.h) \
	loader.h

LDCFG = $(CWD)/app-specific.ld

LDSCRIPT = $(LIBDIR)/rpi64.ld

#####################################################
# OUTPUT
#####################################################

# Mandatory output
IMGFILE = kernel8.img

# Optional outputs
LIST = kernel.list
MAP = kernel.map


#####################################################
# COMPILER AND LINKER
#####################################################

ARMGNU = aarch64-none-elf

CFLAGS = \
	-I $(INCLUDEDIR) \
	-march=armv8-a+simd -mtune=cortex-a53 \
	-Wall -O3 -mstrict-align -fno-tree-loop-vectorize \
	-fno-tree-slp-vectorize \
	-nostdlib -nodefaultlibs -nostartfiles -ffreestanding \
	-fno-asynchronous-unwind-tables -fomit-frame-pointer \

LDFLAGS=-Wl,-gc-sections -Wl,--build-id=none -Wl,-Bdynamic
LIBS = 

#####################################################
# COMPILER AND LINKER
#####################################################

CC = $(ARMGNU)-gcc $(CFLAGS)
AS = $(ARMGNU)-gcc $(CFLAGS)

OBJECTS = $(CFILES:.c=.o) $(ASMFILES:.S=.o)


# Rule to remake everything. Does not include clean.
all: kernel.elf
	$(ARMGNU)-objcopy kernel.elf -O binary $(IMGFILE)
	$(ARMGNU)-objdump -d kernel.elf > $(LIST)
	$(ARMGNU)-nm -n kernel.elf > $(MAP)

# Rule to make the elf file.
kernel.elf : $(OBJECTS) $(LDSCRIPT) $(LDCFG)
	$(ARMGNU)-gcc $(CFLAGS) $(LDFLAGS) \
		-Wl,-T,$(LDSCRIPT) $(OBJECTS) -o $@ $(LIBS)

depend :
	makedepend -I../ $(CFILES)

clean:
	$(RM) kernel8.img
	$(RM) $(MAP)
	$(RM) kernel.elf
	$(RM) $(LIST)
	$(RM) $(OBJECTS)


