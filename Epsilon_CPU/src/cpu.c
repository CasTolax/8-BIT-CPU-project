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

int main(void)
{   
    int A,B;
    A = 10;
    B = 5;

   while (1)
   {
     
      for(int i = 0; i < 256; i++){
        RAM[i] = CPU_MAIN(A,B);
        printf("RAM[%d] = %d\n", i, RAM[i]);
        break;
      }
   }
   
}

int CPU_MAIN(int A, int B)
{   

    switch (sub)
    {
    case add:{

        int result = ADD(A,B);
        printf("%d\n",result);

        RAM[RAM_SIZE+1] = ADD(A,B);
        
        break;
    }
        
    case sub: {
        int result_sub = SUB(A,B);
        printf("%d\n", result_sub);

        RAM[RAM_SIZE+1] = SUB(A,B);
        break;
    }
    
    default:
        break;
    }
    return 0;
}