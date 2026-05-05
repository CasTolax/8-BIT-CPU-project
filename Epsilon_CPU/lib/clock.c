/*
    By CasTolax 2026
*/

#include <stdint.h>
#include "clock.h"
#include <unistd.h>
#include "opcodes.h"

uint8_t PC = 0;
int RAM[RAM_SIZE] = {0};

// clock cycle function
void clock_cycle(void){

    PC++;
    sleep(1);
}