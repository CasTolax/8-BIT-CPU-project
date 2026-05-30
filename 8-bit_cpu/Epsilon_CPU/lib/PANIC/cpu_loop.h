/*
    By CasTolax 2026
*/
#ifndef CPU_LOOP_H
#define CPU_LOOP_H

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_REBOOT  3
#define MAX_HALT    5

/* this is the optional */
typedef enum {
    OP_HALT   = 0xA01,
    OP_REBOOT = 0xA02,
} CPUopcode;

/* this is the also optional */
typedef struct {
    bool     halted;          
    uint16_t boot_address;
    CPUopcode opcode;         
} CPU;

extern CPU cpu;              

int cpu_reboot(void);
int cpu_run(void);



#endif