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
// #include "../lib/scheduler.h" // make another day
#include "../lib/command/write_cache.h"
#include "../lib/interrupts/keyboard_interr.h"

// data of values
typedef struct{

    /* Example values*/
    int A;
    int B;

}data;

// CPU error handling
int cpu_error(void){

    /* struct datas */
    data d;

    /* values */
    d.A = 22;
    d.B = 5;

    /* NULL and zero errors handling */
    if(d.A == 0){
        null_warning();
    } 
    else if(d.B == 0){
        null_warning();
    }
    else{
        return 0;
    }

    /* division process: divided by zero error handling */
    if(DIV(d.A,d.B) == 0){
        zero_division_error();
    }
    else{
        return 0;
    }

    // RAM overflow ERROR
    if(RAM[RAM_SIZE] == 256){
        memory_overflow_error();
    } else {
        return 0;
    }


    return 0;
}

// the MAIN function
int CPU_MAIN(void)
{   
    data d;
    d.A = 22;
    d.B = 5;

    clock_cycle(); // Start the clock cycle
    ALU(d.A,d.B);
    
    /* cache */
    clock_cycle();
    write_cache(RAM); 

    /* Keyboard */   
    keyboard_interrupts(d.A,d.B); 

   /* ALU result printed for commands */  
    output_ALU(d.A,d.B);
   
    return 0;
}

// function called 
int main(void)
{       
    CPU_MAIN(); // Call the function
    cpu_error();

    //run_scheduler(CPU_MAIN);
    return 0;
}

