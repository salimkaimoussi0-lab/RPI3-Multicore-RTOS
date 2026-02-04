#include "variables.h"

// Tableau d'ordres : Case 0 pour CPU0, Case 1 pour CPU1...
DATA_SECTION_ATTR(".data.task_run")
int task_run[3];       