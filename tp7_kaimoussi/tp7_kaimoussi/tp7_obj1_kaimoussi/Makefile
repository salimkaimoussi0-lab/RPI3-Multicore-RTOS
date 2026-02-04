#===============================================================
# FOLDERS
#===============================================================
CWD        = $(shell pwd)
# Base folder for include paths
INCLUDEDIR = $(dir $(CWD))
# All library sources are currently there
LIBDIR     = $(INCLUDEDIR)/librpi3
# All (generated) thread code is here
GENERATED  = $(INCLUDEDIR)/application/gen-t1042
# Provided nodes are here
NODES      = $(INCLUDEDIR)/application/nodes

#####################################################
# SOURCES
#####################################################

ASMFILES = \
	$(LIBDIR)/bcm2837.S \
	$(LIBDIR)/semaphore.S 

CFILES = \
	$(wildcard $(LIBDIR)/*.c) \
	$(wildcard $(GENERATED)/*.c) \
	$(wildcard $(GENERATED)/threads/*.c) \
	$(wildcard $(GENERATED)/wrappers/*.c) \
	$(NODES)/nodes.c \
	main.c \

HEADERS = \
	$(wildcard $(LIBDIR)/*.h)

# Used to specify entry point function name, load
# address, and some other parameters that should not
# change often, but can change.
LDCFG = $(CWD)/app-specific.ld

# Application-independent ldscript
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
	-I $(INCLUDEDIR) -I $(GENERATED) -I $(CWD)\
	-march=armv8-a+simd -mtune=cortex-a53 \
	-Wall -O3 -mstrict-align -fno-tree-loop-vectorize \
	-fno-tree-slp-vectorize \
	-nostdlib -nodefaultlibs -nostartfiles -ffreestanding \
	-fno-asynchronous-unwind-tables -fomit-frame-pointer \

LDFLAGS=-Wl,-gc-sections -Wl,--build-id=none -Wl,-Bdynamic
LIBS = \
#	/Users/dpotop/svn/SENSITIVE/ASSUME-confidential/safran/Livraison_code_compiles/full.a \
#	/Users/dpotop/svn/SENSITIVE/ASSUME-confidential/safran/Livraison_code_compiles/lookup.a \


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
		-Wl,-T,$(LDSCRIPT) $(OBJECTS) -o $@ $(LIBS) $(LIBS)

depend :
	makedepend -I $(INCLUDEDIR) -I $(GENERATED) -I $(CWD) $(CFILES)

clean:
	$(RM) kernel8.img
	$(RM) $(MAP)
	$(RM) kernel.elf
	$(RM) $(LIST)
	$(RM) $(OBJECTS)

# DO NOT DELETE THIS LINE -- make depend depends on it.

/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/arm-config.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/arm.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/arm-config.o: /usr/include/stdint.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/arm-config.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/arm-config.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/arm-config.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/required.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/arm-config.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/uart-mini.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/arm-config.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/stdio.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/arm-config.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/bcm2837.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/ascii-print.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/stdio.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/ascii-print.o: /usr/include/stdint.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/ascii-print.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/ascii-print.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/crc16.o: /usr/include/stdint.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/crc16.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/crc16.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/gpio.o: /usr/include/stdint.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/gpio.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/assert.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/gpio.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/bcm2837.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/gpio.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/gpio.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/mailbox.o: /usr/include/stdint.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/mailbox.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/assert.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/mailbox.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/bcm2837.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/mailbox.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/mailbox.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/mmu-pagetable.o: /usr/include/stdint.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/mmu-pagetable.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/mmu-private.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/mmu-pagetable.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/assert.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/mmu-pagetable.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/arm.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/mmu.o: /usr/include/stdint.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/mmu.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/mmu.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/mmu.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/assert.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/mmu.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/mmu-private.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/mmu.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/arm.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/speed.o: /usr/include/stdint.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/speed.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/mailbox.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/speed.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/speed.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/stdio.o: /usr/include/stdint.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/stdio.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/string.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/stdio.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/stdio.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/string.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/string.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/svc.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/svc.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/svc.o: /usr/include/stdint.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/svc.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/arm.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/svc.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/vector-handlers.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/svc.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/semaphore.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/svc.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/uart-mini.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/uart-mini.o: /usr/include/stdint.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/uart-mini.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/assert.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/uart-mini.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/arm.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/uart-mini.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/bcm2837.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/uart-mini.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/gpio.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/uart-mini.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/mailbox.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/uart-mini.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/uart-mini.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/vector-handlers.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/arm.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/vector-handlers.o: /usr/include/stdint.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/vector-handlers.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/uart-mini.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/vector-handlers.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/stdio.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/vector-handlers.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/vector-handlers.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/vector-handlers.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/svc.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/vector-handlers.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/semaphore.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/vector-handlers.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/bcm2837.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//librpi3/vector-handlers.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/arm-config.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//application/gen-t1042/syncvars.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/application/gen-t1042/syncvars.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//application/gen-t1042/syncvars.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/application/api_lopht.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//application/gen-t1042/syncvars.o: /usr/include/stdint.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//application/gen-t1042/syncvars.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/semaphore.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//application/gen-t1042/variables.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/application/gen-t1042/variables.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//application/gen-t1042/variables.o: extern-types.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//application/gen-t1042/variables.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/application/api_lopht.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//application/gen-t1042/variables.o: /usr/include/stdint.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//application/gen-t1042/variables.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/semaphore.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//application/gen-t1042/threads/thread_cpu0.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/application/api_lopht.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//application/gen-t1042/threads/thread_cpu0.o: /usr/include/stdint.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//application/gen-t1042/threads/thread_cpu0.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/semaphore.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//application/gen-t1042/threads/thread_cpu0.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/application/gen-t1042/syncvars.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//application/gen-t1042/threads/thread_cpu0.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/application/gen-t1042/nodes.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//application/gen-t1042/threads/thread_cpu0.o: extern-types.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//application/gen-t1042/threads/thread_cpu0.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/application/gen-t1042/variables.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//application/gen-t1042/threads/thread_cpu0.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/application/gen-t1042/threads.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//application/gen-t1042/threads/thread_cpu1.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/application/api_lopht.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//application/gen-t1042/threads/thread_cpu1.o: /usr/include/stdint.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//application/gen-t1042/threads/thread_cpu1.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/semaphore.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//application/gen-t1042/threads/thread_cpu1.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/application/gen-t1042/syncvars.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//application/gen-t1042/threads/thread_cpu1.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/application/gen-t1042/nodes.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//application/gen-t1042/threads/thread_cpu1.o: extern-types.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//application/gen-t1042/threads/thread_cpu1.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/application/gen-t1042/variables.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//application/gen-t1042/threads/thread_cpu1.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/application/gen-t1042/threads.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//application/nodes/nodes.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/stdio.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//application/nodes/nodes.o: /usr/include/stdint.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//application/nodes/nodes.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/svc.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//application/nodes/nodes.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/arm.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//application/nodes/nodes.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/vector-handlers.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//application/nodes/nodes.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/semaphore.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//application/nodes/nodes.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/application/gen-t1042/nodes.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//application/nodes/nodes.o: extern-types.h
/home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime//application/nodes/nodes.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/application/api_lopht.h
main.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/uart-mini.h
main.o: /usr/include/stdint.h
main.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/semaphore.h
main.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/stdio.h
main.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/arm-config.h
main.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/svc.h
main.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/arm.h
main.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/librpi3/vector-handlers.h
main.o: /home/alaouiy/demo-test/aarch64-cortexA53-rpi3-runtime/application/gen-t1042/threads.h
