#include "nodes.h"
#include <stdbool.h>
#include <limits.h>


static scheduler_state ss;


extern void deadline_miss_log(int date, int tid);


/* EDF: Sélectionner le processeur avec la deadline la plus grande (pour le remplacer) */
static int select_largest_deadline(int selected_deadlines[N_PROC]) {
    int ld = 0;
    int max_deadline = selected_deadlines[0];
    for (int i = 1; i < N_PROC; i++) {
        if (selected_deadlines[i] > max_deadline) {
            max_deadline = selected_deadlines[i];
            ld = i;
        }
    }
    return ld;
}



static void select_tasks(task_status ts[N_TASKS], int selected[N_PROC]) {


    int selected_deadlines[N_PROC];
    for (int i = 0; i < N_PROC; i++) {
        selected[i] = N_TASKS;
        selected_deadlines[i] = INT_MAX;
    }


    for (int tid = 0; tid < N_TASKS; tid++) {
        if (ts[tid].status == Ready) {
            /* Trouver le processeur avec la deadline la plus grande */
            int ld = select_largest_deadline(selected_deadlines);
            

            if (ts[tid].current_deadline < selected_deadlines[ld]) {
                selected[ld] = tid;
                selected_deadlines[ld] = ts[tid].current_deadline;
            }
        }
    }
}


static int update_aux(int selected[N_PROC], int tid) {
    for (int proc_id = 0; proc_id < N_PROC; proc_id++) {
        if (selected[proc_id] == tid) {
            return proc_id;
        }
    }
    return N_PROC; // Non alloué
}


static void update_selected_mc(task_status ts[N_TASKS], int selected[N_PROC]) {
    for (int tid = 0; tid < N_TASKS; tid++) {
        int proc_id = update_aux(selected, tid);
        if (proc_id != N_PROC) {
            ts[tid].status = Running;
            ts[tid].current_proc = proc_id;
        }
    }
}


/* EDF multi-cœurs - remplace rate_monotonic_mc */
static void earliest_deadline_first_mc(task_status ts[N_TASKS]) {
    int selected[N_PROC];
    select_tasks(ts, selected);
    update_selected_mc(ts, selected);
}


static void complete(task_status *tsi, bool task_end) {
    if (task_end) {

        tsi->status = Waiting;
        tsi->left = 0;
        tsi->current_proc = N_PROC;
    } else if (tsi->status == Running) {
  
        tsi->status = Ready;
        tsi->left = tsi->left - 1;
        tsi->current_proc = N_PROC;
    }
}


static void check_deadline(int current_date, task_status *tsi, int tid) {
    if (tsi->status == Ready && tsi->current_deadline == current_date) {
        deadline_miss_log(current_date, tid);
        tsi->status = Waiting;
    }
}


static void start_inst(int current_date, task_status *tsi, const task_attributes *ta) {
    if ((current_date - ta->first_start) % ta->period == 0) {
        tsi->status = Ready;
        tsi->current_deadline = current_date + ta->deadline;
        tsi->left = ta->capacity; 
        tsi->current_proc = N_PROC;
    }
}


static void extract_proc(task_status ts[N_TASKS], int task_run[N_PROC]) {
    for (int i = 0; i < N_PROC; i++) {
        task_run[i] = N_TASKS; 
    }

    for (int tid = 0; tid < N_TASKS; tid++) {
        if (ts[tid].status == Running) {
            int proc_id = ts[tid].current_proc;
            if (proc_id < N_PROC) {
                task_run[proc_id] = tid;
            }
        }
    }
}



void scheduler_reset() {
    ss = init_sstate;
}

void scheduler_step(const int task_end[N_TASKS], int task_run[N_PROC]) {
    ss.current_date++;


    for (int i = 0; i < N_TASKS; i++) {
        complete(&ss.tasks[i], task_end[i]);
    }


    for (int i = 0; i < N_TASKS; i++) {
        check_deadline(ss.current_date, &ss.tasks[i], i);
    }


    for (int i = 0; i < N_TASKS; i++) {
        start_inst(ss.current_date, &ss.tasks[i], &tasks[i]);
    }


    /* Utilisation de EDF au lieu de RM */
    earliest_deadline_first_mc(ss.tasks);


    extract_proc(ss.tasks, task_run);
}
