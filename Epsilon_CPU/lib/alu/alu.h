/*
    By CasTolax 2026
*/

#ifndef ALU_H
#define ALU_H

#include <stdint.h>

int ALU (int A, int B); // prototype function

static inline uint8_t ADD (uint8_t A, uint8_t B)
{   
    uint8_t result = A + B;
    return result;
}

static inline uint8_t SUB (uint8_t A, uint8_t B)
{   
    uint8_t result = A - B;
    return result;
}

static inline uint8_t MUL (uint8_t A, uint8_t B)
{   
    uint8_t result = A * B;
    return result;
}

static inline uint8_t DIV (uint8_t A, uint8_t B)
{   
    uint8_t result = A / B;
    return result;
}

#endif
