/*
    * By CasTolax 2026
*/

#ifndef CLOCK_H
#define CLOCK_H

#include <stdint.h>

// Program sayacı: CPU'nun hangi adımda olduğunu tutar.
extern uint8_t PC;

void clock_cycle(void);

#endif
