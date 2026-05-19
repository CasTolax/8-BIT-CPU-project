/*
    By CasTolax 2026
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "alu.h"
#include "../opcodes.h"
#include "../clock.h"

bool alu_active = true;

int ALU (int A, int B)
{        
    printf("\n Ram is ready... \n ");
    
    int WRITING = 0; // writing start at 0

    /*
    there is calculations about A and B, when output is ready,
    RAM writing and print to screen with adress.
    */

    int result = ADD(A,B);
    int result_sub = SUB(A,B);
    int result_mul = MUL(A,B);    
    int result_div = DIV(A,B);    
   
    // load result in RAM
    RAM[WRITING++] = ADD(A,B);
    RAM[WRITING++] = SUB(A,B);
    RAM[WRITING++] = MUL(A,B);
    RAM[WRITING++] = DIV(A,B);

    // output ---
    for(int i = 0; i < 256; i++){
        
        if(i % 16 == 0){
            printf("\n%03d: ", i);
        }
        printf("%4d ", RAM[i]);
      }
   printf("\n");

   printf("0x01 = %d\n",result);
   printf("0x02 = %d\n", result_sub);
   printf("0x03 = %d\n",result_mul);
   printf("0x04 = %d\n",result_div);


    return 0;
}
