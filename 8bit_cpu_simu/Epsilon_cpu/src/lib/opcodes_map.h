/*
    * By CasTolax
*/

#ifndef OPCODES_MAP_H
#define OPCODES_MAP_H

// Data movement
#define LDA      0x10   // load A from memory
#define LDB      0x11   // load B from memory
#define STA      0x12   // A in info to load RAM
#define STB      0x13   // B in info to load RAM
#define MOV_AB   0x14   // register copy: register --> register
#define MOV_BA   0x15   // register copy: register --> register
#define LDI_A    0x16   // const A
#define LDI_B    0x17   // const B

// Arithmetic
#define ADD      0x20   // process A + B
#define SUB      0x21   // process A - B
#define MUL      0x22   // process A * B
#define DIV      0x23   // process A / B
#define MOD      0x24   // process A % B

// Logic (bitwise operations)
#define AND      0x30
#define OR       0x31
#define XOR      0x32
#define NOT      0x33
#define SHL      0x34
#define SHR      0x35

// Control flow (FLAGS)
#define JMP      0x40   // change
#define JZ       0x41   // control PC or anything
#define JNZ      0x42   // control PC or anything
#define CALL     0x43   // call function
#define RET      0x44   // get info from STACK

// Compare
/*
    *  Sometimes you don’t want to hide the result... 
    *  and sometimes you just want to compare...
    * 
    * use:
    * CMP A,B
    * JZ equal
*/
#define CMP      0x50   

// Stack
#define PUSH_A   0x60   // data storage
#define PUSH_B   0x61   // data storage
#define POP_A    0x62   // get data from storage
#define POP_B    0x63   // get data from storage

// I/O
#define IN       0x70 // input
#define OUT      0x71 // output 

// System
#define NOP      0x80   // for pipeline/debug
#define HLT      0x81   // stop CPU
#define CLR_A    0x82   // clear A
#define CLR_B    0x83   // clear B


#endif