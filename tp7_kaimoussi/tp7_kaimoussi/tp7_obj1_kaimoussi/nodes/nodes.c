#include "nodes.h"
#include <librpi3/svc.h>
#include <librpi3/stdio.h>
#include <librpi3/uart-mini.h>


const task_attributes tasks[N_TASKS] = {
  { .period = 7,  .capacity = 1, .deadline = 7,  .first_start = 1 }, // task0
  { .period = 5,  .capacity = 1, .deadline = 5,  .first_start = 1 }, // task1
  { .period = 6,  .capacity = 1, .deadline = 6,  .first_start = 3 }, // task2
  { .period = 8,  .capacity = 1, .deadline = 8,  .first_start = 2 }, // task3
  { .period = 10, .capacity = 1, .deadline = 10, .first_start = 2 }  // task4
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
void task2(void) {
    // même style que task0/task1 (affichage, charge, etc.)
    // exemple minimal: juste un message
    char buf[64];
    uint32_t cpuid = get_cpuid();
    snprintf(buf, sizeof(buf), "Core %u: Executing Task 2\n", cpuid);
    console_puts(cpuid, buf);
}

void task3(void) {
    char buf[64];
    uint32_t cpuid = get_cpuid();
    snprintf(buf, sizeof(buf), "Core %u: Executing Task 3\n", cpuid);
    console_puts(cpuid, buf);
}

void task4(void) {
    char buf[64];
    uint32_t cpuid = get_cpuid();
    snprintf(buf, sizeof(buf), "Core %u: Executing Task 4\n", cpuid);
    console_puts(cpuid, buf);
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