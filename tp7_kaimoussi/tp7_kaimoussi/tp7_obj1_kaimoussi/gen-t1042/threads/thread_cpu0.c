#include "api_lopht.h"
#include "nodes.h"
#include "threads.h"
#include "syncvars.h"

#include <librpi3/stdio.h>   // snprintf
#include <librpi3/svc.h>     // get_cpuid(), console_puts()

static unsigned tick = 0;

void mif_end_point0(void);

int task_end[N_TASKS];
int task_run[N_PROC];

__attribute__((always_inline))
inline void mif_reinit(void) {
    mif_cnt = (mif_cnt + 1) % 1;
    loc_pc_1 = -1;
    UPDATE_CPU(loc_pc_0, -1);
}

SECTION_ATTR(".text.cpu0")
__attribute__((noinline))
void global_init(void) {

    scheduler_reset();

    for (int i = 0; i < N_TASKS; i++) task_end[i] = 0;
    for (int i = 0; i < N_PROC;  i++) task_run[i] = N_TASKS; // idle par défaut

    mif_cnt = -1;
    mif_reinit();
}

SECTION_ATTR(".text.cpu0")
void mif_entry_point_cpu0(void) {


    scheduler_step(task_end, task_run);


    {
        char buf[128];
        uint32_t cpuid = get_cpuid();

        if (N_PROC >= 2) {
            snprintf(buf, sizeof(buf),
                     "[tick %u] run: cpu0=%d cpu1=%d\n",
                     tick, task_run[0], task_run[1]);
        } else {
            snprintf(buf, sizeof(buf),
                     "[tick %u] run: cpu0=%d\n",
                     tick, task_run[0]);
        }

        console_puts(cpuid, (char*)buf);
        tick++;
    }


    for (int i = 0; i < N_TASKS; i++) task_end[i] = 0;


    UPDATE_CPU(loc_pc_0, 1);


    switch (task_run[0]) {

        case 0:
            task0();
            task_end[0] = 1;
            break;

        case 1:
            task1();
            task_end[1] = 1;
            break;

        case N_TASKS:
            // idle: rien à exécuter sur CPU0 ce tick
            break;

        default: {
            char buf[96];
            uint32_t cpuid = get_cpuid();
            snprintf(buf, sizeof(buf),
                     "Error: invalid task id on cpu0=%d\n",
                     task_run[0]);
            console_puts(cpuid, (char*)buf);
            break;
        }
    }


    WAIT_CPU(loc_pc_1, 2);


    loc_pc_1 = -1;
    UPDATE_CPU(loc_pc_0, -1);

    mif_end_point0();
}

SECTION_ATTR(".text.cpu0")
__attribute__((noinline, noreturn))
void mif_end_point0(void) {

    UPDATE_CPU(loc_pc_0, 10000);
    WAIT_CPU(loc_pc_1, 10000);

    mif_reinit();

    for (;;);
}
