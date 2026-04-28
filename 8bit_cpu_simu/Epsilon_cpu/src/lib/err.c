/*
    By CasTolax 2026
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "Epsilon_cpu/src/lib/commands/commands.h"
#include "Epsilon_cpu/src/cpu/cpu.h"
#include "Epsilon_cpu/src/lib/alu.h"

#include "err.h"

// print screen error.
void err_print(const char *str);

// when input is ZERO in division process.
void err_ZERO(void);

// when CPU make NULL output or input.
void err_NULL(void);

void err_print(const char *str)
{
    while(*str){
        putchar(*str);
        str++;
    }
}

void err_ZERO(void){
    err_print("You can not division with ZERO! err_ZERO error \n");
}

void err_NULL(void){
    err_print("NULL ERROR err_NULL \n");
}

static inline char err_main(void)
{   
   // TEST : err_print("merhaba ERROR \n");  
   return 0;  
}
