/*
    errors.h - error handling for Epsilon CPU
    By CasTolax 2026
*/

#ifndef ERRORS_H
#define ERRORS_H


#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// when calculations is divided with zero, this function will be called.
void zero_division_error(void);

// when invalid process is enable, simulation is shutdown(ıdk)
void invalid_process_error(void);

// The RAM when overflow, this error handling will be called.
void memory_overflow_error(void);

/* If the output is empty (0 or NULL), it will issue a warning rather than an error. This way, 
if the result of an operation is NULL, it will issue this warning after it has been written to RAM.*/
void null_warning(void);

// Print the error message to the screen. Since this function is defined as static inline,
// no errors will occur even if it is included in multiple files.
static inline void print_ERROR(const char* error_message){
    printf("ERROR: %s\n", error_message);
}

#endif
