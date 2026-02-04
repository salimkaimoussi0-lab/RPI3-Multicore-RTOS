#include "threads.h"
#include "variables.h"
#include "syncvars.h"
#include "nodes.h"

#define WAIT_END(var) while(api_ldar(&var)!=-1)

void mif_entry_point_cpu2(void) {
    // Attendre l'ordre (comme CPU 1)
    WAIT_CPU(loc_pc_0, 1);

    // Exécuter la tâche demandée (T2 ou T5)
    if (task_run[2] == 2) task2();
    if (task_run[2] == 5) task5();

    // Signaler "J'ai fini"
    UPDATE_CPU(loc_pc_2, 2);
    
    // Attendre le reset
    WAIT_END(loc_pc_0);
}

