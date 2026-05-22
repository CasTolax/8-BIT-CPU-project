/*
    * By CasTolax

    * The flag register adress are here -->
    /lib/registers/Fregisters
*/

#ifndef OPCODES_H
#define OPCODES_H

// OPCODES MAP

#define RAM_SIZE 256       // size of the RAM
extern int RAM[RAM_SIZE];    // RAM array

#define CPU_START 1    // start of the CPU
#define reserved  0x0ff
#define add 0x01       // addition
#define sub 0x02       // subtraction
#define mul 0x03       // multiplication
#define div 0x04       // division


// I/0
#define sys_status 0xBe1 // system status
#endif 
