#include "threads.h"
#include "variables.h"
#include "syncvars.h"
#include "nodes.h"

static int time = 0;
void global_init(void) {}

void mif_entry_point_cpu0(void) {
    
    // 1. RESET des ordres
    task_run[0] = 0; // Pour CPU 0
    task_run[1] = 0; // Pour CPU 1
    task_run[2] = 0; // Pour CPU 2

    // --- ORDONNANCEMENT ---
    
    // Tâche 1 (Période 7) -> CPU 1
    if ((time % 7) == 0) task_run[1] = 1;
    
    // Tâche 2 (Période 5) -> CPU 2
    if ((time % 5) == 0) task_run[2] = 2;
    
    // Tâche 3 (Période 6) -> CPU 0 (Le Chef se donne du travail)
    if ((time % 6) == 0) task_run[0] = 3;
    
    // Tâche 4 (Période 8) -> CPU 1 (Si libre)
    if ((time % 8) == 0) {
        if (task_run[1] == 0) task_run[1] = 4;
    }

    // Tâche 5 (Période 10) -> CPU 2 (Si libre)
    if ((time % 10) == 0) {
        if (task_run[2] == 0) task_run[2] = 5;
    }

    time++; 

    // 2. DONNER LE TOP DÉPART
    UPDATE_CPU(loc_pc_0, 1);

    // 3. TRAVAILLER (Si le Chef a une tâche)
    if (task_run[0] == 3) task3(); 

    // 4. ATTENDRE LES 2 OUVRIERS (CPU 1 et CPU 2)
    WAIT_CPU(loc_pc_1, 2);
    WAIT_CPU(loc_pc_2, 2);

    // 5. RESET et FIN DE CYCLE
    loc_pc_1 = -1;
    loc_pc_2 = -1;
    UPDATE_CPU(loc_pc_0, -1);
}
