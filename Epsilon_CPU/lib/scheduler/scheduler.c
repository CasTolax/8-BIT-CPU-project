/*
    By CasTolax 2026
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "scheduler.h"

/*
    * It will loop continuously; if all tasks are complete, it will exit.
    * If there is a task -> process it for the specified duration and move on to the next one
    * If there are tasks that haven't finished yet -> add them to the queue
    * If a task is ready to be processed -> start it
    * If it finishes  = set to TERMINATED
    * If there are tasks that haven't finished yet, check them
    * Exit
    * Repeat the tasks
 
*/

/* building with AI! */
void run_scheduler(Process p[])
{   

    int finished = 0;

    while(finished < PROCESS_COUNT)
    {
        for(int i = 0; i<PROCESS_COUNT; i++){

            if(p[i].state == TERMINATED)
            continue;

            p[i].state = RUNNING;

            printf("Process %d running\n", p[i].pid);

            int work = QUANTUM;

            if(p[i].remaining_time < QUANTUM)
                work = p[i].remaining_time;

            p[i].remaining_time -= work;

            printf("Reamaining: %d\n", p[i].remaining_time);

            if(p[i].remaining_time <= 0)
            {
                p[i].state = TERMINATED;
                finished++;

                printf("Process %d terminated\n", p[i].pid);
            }
            else{
                p[i].state = READY;
            }
        }
    }





    return 0;
}
