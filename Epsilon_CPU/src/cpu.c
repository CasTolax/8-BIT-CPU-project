/*
    * By CasTolax 2026
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "cpu.h" // prototype of CPU_MAIN
#include "../lib/alu/alu.h"
#include "../lib/opcodes.h"
#include "../lib/err/errors.h"

#include "../lib/clock.h"

int CPU_MAIN(void)
{   
    /* example values */
    int A = 100;
    int B = 5;

    clock_cycle(); // Start the clock cycle
    ALU(A,B);

    if(DIV(A,B) == 0){
        zero_division_error();
    }
    return 0;
}

int main(void)
{       
    CPU_MAIN(); // Call the function
   
    return 0;
}

