#ifndef NODES_H
#define NODES_H

#include <stdint.h>


typedef enum { Waiting, Ready, Running } task_state;

typedef struct {
    int period;
    int capacity;
    int deadline;
    int first_start;
} task_attributes;


#define N_TASKS 2
#define N_PROC 2
#define INT_MAX 2147483647

typedef struct {
    task_state status;
    int current_deadline;
    int left;
    int current_proc; 
} task_status;

typedef struct {
    int current_date;
    task_status tasks[N_TASKS];
} scheduler_state;


extern const task_attributes tasks[N_TASKS];
extern const scheduler_state init_sstate;


void scheduler_reset(void);
void scheduler_step(const int task_end[N_TASKS], int task_run[N_PROC]);


void task0(void);
void task1(void);


void deadline_miss_log(int date, int task_id);
int random(int max);
void print_scheduler_state(scheduler_state s);

#endif // NODES_H
