#include <librpi3/uart-mini.h>
#include <librpi3/semaphore.h>
#include <librpi3/stdio.h>
#include <librpi3/arm-config.h>
#include <librpi3/svc.h>
#include "gen-t1042/threads.h"



__attribute__((weak))
__attribute__((noreturn))
void mif_entry_point_cpu0(void) {
  for(;;) ;
}
__attribute__((weak))
__attribute__((noreturn))
void mif_entry_point_cpu1(void) {
  for(;;) ;
}
__attribute__((weak))
__attribute__((noreturn))
void mif_entry_point_cpu2(void) {
  for(;;) ;
}
__attribute__((weak))
__attribute__((noreturn))
void mif_entry_point_cpu3(void) {
  for(;;) ;
}



volatile uint32_t bss_not_initialized = 1 ;

__attribute__((noreturn))
__attribute__((section(".init")))
void el0_main(uint64_t cpuid) {
 
  if((cpuid==0)&&(bss_not_initialized)) {
    bss_init() ;
    asm volatile("dmb sy") ;
    bss_not_initialized = 0 ;

    global_init() ;
  }
  while(bss_not_initialized) ;


  
  switch(cpuid) {
  case 0:
    mif_entry_point_cpu0() ;
    break ;
  case 1:
    mif_entry_point_cpu1() ;
    break ;
  case 2:
    mif_entry_point_cpu2() ;
    break ;
  case 3:
    mif_entry_point_cpu3() ;
    break ;
  default:
    break ;
  }
  for(;;) ;
}
