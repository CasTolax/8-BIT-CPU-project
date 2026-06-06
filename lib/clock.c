/*
    By CasTolax 2026
*/

#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>

#include "clock.h"
#include "opcodes.h"

uint8_t PC = 0;
int RAM[RAM_SIZE] = {0};
bool clock_active = true;


// clock cycle function
void clock_cycle(void){

    PC++;
    sleep(1);
}