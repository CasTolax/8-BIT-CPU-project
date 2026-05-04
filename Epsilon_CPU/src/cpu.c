/*
    * By CasTolax 2026
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "cpu.h" // prototype of CPU_MAIN
#include "../lib/alu/alu.h"
#include "../lib/opcodes.h"
#include "../lib/clock.h"


int CPU_MAIN(void)
{   

    int WRITING = 0; // writing start at 0

    int A = 10; // example
    int B = 5;  // example

    /*
    there is calculations about A and B, when output is ready,
    RAM writing and print to screen with adress. 
    */
    int result = ADD(A,B);    
    printf("0x01 = %d\n",result);

    int result_sub = SUB(A,B);
    printf("0x02 = %d\n ", result_sub);

    RAM[WRITING++] = ADD(A,B);
    RAM[WRITING++] = SUB(A,B);

    return 0;
}



int main(void)
{   
    CPU_MAIN();
    for(int i = 0; i < 256; i++){
        
        if(i % 16 == 0){
            printf("\n%03d: ", i);
        }
        printf("%4d ", RAM[i]);
      }
   printf("\n");
     
}

