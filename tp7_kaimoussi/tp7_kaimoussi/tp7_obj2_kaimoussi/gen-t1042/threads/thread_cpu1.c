#include "threads.h"
#include "variables.h"
#include "syncvars.h"
#include "nodes.h"

#define WAIT_END(var) while(api_ldar(&var)!=-1)

void mif_entry_point_cpu1(void) {
    // Attendre l'ordre
    WAIT_CPU(loc_pc_0, 1);

    // Exécuter la tâche demandée
    if (task_run[1] == 1) task1();
    if (task_run[1] == 4) task4();

    // Signaler "J'ai fini"
    UPDATE_CPU(loc_pc_1, 2);
    
    // Attendre le reset du chef
    WAIT_END(loc_pc_0);
}