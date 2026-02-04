#ifndef SYNCVARS_H
#define SYNCVARS_H

#include <stdint.h>

// Variables de synchronisation entre cœurs
extern volatile int loc_pc_0;
extern volatile int loc_pc_1;
extern volatile int mif_cnt;

#endif // SYNCVARS_H
