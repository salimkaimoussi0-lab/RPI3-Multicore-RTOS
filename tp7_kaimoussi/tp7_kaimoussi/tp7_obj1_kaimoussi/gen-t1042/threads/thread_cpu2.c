#include "api_lopht.h"
#include "nodes.h"
#include "threads.h"
#include "syncvars.h"

void mif_end_point2(void);

extern int task_end[N_TASKS];
extern int task_run[N_PROC];

SECTION_ATTR(".text.cpu2")
void mif_entry_point_cpu2(void){


    WAIT_CPU(loc_pc_0,1);

    int task_id = task_run[2];

    if (task_id < N_TASKS) {
        switch (task_id) {

            case 0:
                task0();
                task_end[0] = 1;
                break;

            case 1:
                task1();
                task_end[1] = 1;
                break;

            case 2:
                task2();
                task_end[2] = 1;
                break;

            case 3:
                task3();
                task_end[3] = 1;
                break;

            case 4:
                task4();
                task_end[4] = 1;
                break;

            default:
                // erreur silencieuse
                break;
        }
    } else {
        // idle: rien à faire (task_id == N_TASKS)
    }

    // Signaler à CPU0 qu'on a fini le tick
    UPDATE_CPU(loc_pc_2,2);

    // Attendre la fin de cycle (CPU0 remet loc_pc_0 = -1)
    WAIT_END(loc_pc_0);

    mif_end_point2();
}

SECTION_ATTR(".text.cpu2")
__attribute__((noinline,noreturn))
void mif_end_point2 (void){

    UPDATE_CPU(loc_pc_2,10000);

    WAIT_CPU(loc_pc_0,10000);

    for(;;);
}

