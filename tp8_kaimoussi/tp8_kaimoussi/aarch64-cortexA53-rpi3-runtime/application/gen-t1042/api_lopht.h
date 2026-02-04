#ifndef API_LOPHT_H
#define API_LOPHT_H

#include <librpi3/semaphore.h>
#include <librpi3/arm-config.h>

// Variables de synchronisation
extern volatile int loc_pc_0;
extern volatile int loc_pc_1;
extern volatile int mif_cnt;

// Macros de synchronisation
#define UPDATE_CPU(var, val) do { var = val; asm volatile("dmb sy"); } while(0)
#define WAIT_CPU(var, val) do { while(var != val); asm volatile("dmb sy"); } while(0)
#define WAIT_END(var) WAIT_CPU(var, 10000)
#define SECTION_ATTR(x) __attribute__((section(x)))

#endif // API_LOPHT_H
