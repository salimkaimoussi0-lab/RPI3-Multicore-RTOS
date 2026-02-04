void burn_cpu(void) {
    volatile int i;
    for(i=0; i<500000; i++); 
}

void task1(void) { burn_cpu(); }
void task2(void) { burn_cpu(); }
void task3(void) { burn_cpu(); }
void task4(void) { burn_cpu(); }
void task5(void) { burn_cpu(); }