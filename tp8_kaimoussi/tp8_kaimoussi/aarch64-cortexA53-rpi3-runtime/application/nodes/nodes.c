#include "nodes.h"
#include <librpi3/svc.h>
#include <librpi3/stdio.h>
#include <librpi3/uart-mini.h>


const task_attributes tasks[N_TASKS] = {
    { .period = 5, .capacity = 2, .deadline = 5, .first_start = 0 },
    { .period = 7, .capacity = 4, .deadline = 7, .first_start = 0 }
};


void task0(void) {
    char strbuf[128];
    int cpuid = get_cpuid();
    snprintf(strbuf, 127, "Core %d: Executing Task 0\n", cpuid);
    console_puts(cpuid, strbuf);
    
    // Simuler une charge de travail
    volatile int sum = 0;
    for (int i = 0; i < 100000; i++) {
        sum += i;
    }
}


void task1(void) {
    char strbuf[128];
    int cpuid = get_cpuid();
    snprintf(strbuf, 127, "Core %d: Executing Task 1\n", cpuid);
    console_puts(cpuid, strbuf);
    

    volatile int sum = 0;
    for (int i = 0; i < 100000; i++) {
        sum += i;
    }
}


void deadline_miss_log(int date, int task_id) {
    char strbuf[128];
    snprintf(strbuf, 127, "DEADLINE MISS: Task %d at date %d\n", task_id, date);
    console_puts(0, strbuf);
}


int random(int max) {
    return 0;
}


void print_scheduler_state(scheduler_state s) {

}


const scheduler_state init_sstate = {
    .current_date = -1,
    .tasks = {
        { .status = Waiting, .current_deadline = 0, .left = 0, .current_proc = N_PROC },
        { .status = Waiting, .current_deadline = 0, .left = 0, .current_proc = N_PROC }
    }
};
