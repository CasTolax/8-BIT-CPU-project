/*
    By CasTolax 2026
*/

#ifndef ALU_H
#define ALU_H

#include <stdint.h>
#include <stdbool.h>
#include "../lib/opcodes.h"

/*
    The arithmetic logic unit has an 8-bit data bus and processing power, 
    and the expandable data bus is 256 bytes wide.

    It can also perform mathematical operations 
    (and can be modified to suit individual needs if desired).
*/

extern bool alu_active;

int ALU (int A, int B); 

void RAM_RESET(void);

static inline uint16_t ADD(uint8_t A, uint8_t B)
{   
    return (uint16_t)A + (uint16_t)B;
}
static inline uint16_t SUB(uint8_t A, uint8_t B)
{   
    return (uint16_t)A - (uint16_t)B;
}
static inline uint16_t MUL(uint8_t A, uint8_t B)
{   
    return (uint16_t)A * (uint16_t)B;
}
static inline uint16_t DIV(uint8_t A, uint8_t B)
{   
    return (uint16_t)A / (uint16_t)B;
}

#endif
