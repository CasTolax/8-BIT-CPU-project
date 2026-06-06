/*
    By CasTolax 2026
*/


#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stdint.h>

#define PROCESS_COUNT 10  // sadece 10 tane iş yapılacak
#define QUANTUM 2 // sadece 2 tick 


typedef enum
{
    READY,  // hazır olduğunda
    RUNNING, // çalışıyorken
    COMPLETED // bitirildiği zaman
    
}Process;


typedef struct 
{
    int pid; // process kimlik
    int remaining_time; // kalan süre

}ProcessState;


// prototype function
void run_scheduler(Process p[]);


#endif