/*
    errors.c - error handling implementation for Epsilon CPU
    By CasTolax 2026
*/

#include <stdio.h>
#include <stdlib.h>
#include "errors.h"

// Division by zero error
// This function is called when the divisor is zero in fractional calculations.
void zero_division_error(void) {
    fprintf(stderr, "ERROR: Division by zero!\n");
    exit(EXIT_FAILURE);
}

// Invalid instruction error
// This function is called if the CPU attempts to execute an invalid instruction code.
void invalid_process_error(void) {
    fprintf(stderr, "ERROR: Invalid process/instruction!\n");
    exit(EXIT_FAILURE);
}

// Out-of-memory error
// This function is called if the RAM limit is exceeded.
void memory_overflow_error(void) {
    fprintf(stderr, "ERROR: Memory overflow!\n");
    exit(EXIT_FAILURE);
}

// Error Handling for cache
/*
    When the Cache is the fully of values, theoretically
    this function will be called
*/
void cache_overflow_error(void){

    if(CACHE_SIZE == 64){

        fprintf(stderr, "ERROR: CACHE overflow!\n");
        exit(EXIT_FAILURE);
    }
    
}

// if, there is a NULL or empyt variable and value, this function will be called
void null_warning(void){
    fprintf(stderr, "WARNING: there is a NULL output or input variable, writing in RAM... \n");
    exit(EXIT_FAILURE);
}
