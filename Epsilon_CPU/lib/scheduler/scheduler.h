/*
    By CasTolax 2026
*/


#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stdint.h>

#define PROCESS_COUNT 3     
#define QUANTUM 2           // tick time

typedef enum {

    READY,          // when the process are ready
    RUNNING,        // Process are running
    TERMINATED      // proceess is finish

}ProcessSTATE;

typedef struct{

    int pid;                // Process ID
    int remaining_time;     // Remaining task time
    ProcessSTATE state;     // Enum: ProcessSTATE to state

}Process;

// prototype function
void run_scheduler(Process p[]);


#endif