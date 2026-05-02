/*
    By CasTolax 2026
*/

#ifndef WRITE_H
#define WRITE_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "Epsilon_cpu/src/lib/mem_map.h"

void write(uint8_t addr, uint8_t val){
    
    RAM[addr] = val;
}

#endif
