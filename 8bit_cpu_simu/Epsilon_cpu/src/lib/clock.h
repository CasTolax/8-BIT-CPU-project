/*
    * By CasTolax 2026
*/

#ifndef CLOCK_H
#define CLOCK_H

#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include "gates.h"
#include "mem_map.h"
#include "opcodes_map.h"

// clock LOW-HIGH
int FLIP = 0;

// sleep time: 0.5,1,5,10 seconds
void SLEEP(int number)
{   

    switch (number)
    {
    case 0: // 0.5
        while(1){

            FLIP ^= 1;
            printf("%d\n",FLIP);
            sleep(0.5);

        }
        break;
    case 1:
        while(1){

            FLIP ^= 1;
            printf("%d\n", FLIP);

            sleep(1);
        }    
        break;
    case 5:
        while(1){

            FLIP ^= 1;
            printf("%d\n", FLIP);
            
            sleep(5);
        }
        break;
    case 10:
        while(1){

            FLIP ^= 1;
            printf("%d\n", FLIP);
            sleep(10);

        }
        break;
    default:
        break;
    }
}



#endif