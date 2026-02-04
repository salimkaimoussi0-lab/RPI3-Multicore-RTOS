#include "api_lopht.h"
#include "nodes.h"
#include "threads.h"
#include "syncvars.h"

void mif_end_point1(void);

extern int task_end[N_TASKS];
extern int task_run[N_PROC];

SECTION_ATTR(".text.cpu1")
void mif_entry_point_cpu1(void){

    WAIT_CPU(loc_pc_0,1);

    int task_id = task_run[1];

    if (task_id < N_TASKS) {
        switch (task_id) {
            case 0: task0(); task_end[0] = 1; break;
            case 1: task1(); task_end[1] = 1; break;
            case 2: task2(); task_end[2] = 1; break;
            case 3: task3(); task_end[3] = 1; break;
            case 4: task4(); task_end[4] = 1; break;
            default: break;
        }
    } else {
        // idle (task_id == N_TASKS)
    }

    UPDATE_CPU(loc_pc_1,2);
    WAIT_END(loc_pc_0);

    mif_end_point1();
}

SECTION_ATTR(".text.cpu1")
__attribute__((noinline,noreturn))
void mif_end_point1 (void){
    UPDATE_CPU(loc_pc_1,10000);
    WAIT_CPU(loc_pc_0,10000);
    for(;;);
}
