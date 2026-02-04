#include "variables.h"

// IMPORTANT : Tableau de taille 3 pour gérer CPU 0, 1 et 2
DATA_SECTION_ATTR(".data.task_run")
int task_run[3];