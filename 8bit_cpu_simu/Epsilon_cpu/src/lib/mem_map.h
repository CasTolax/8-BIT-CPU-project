/*
    * By CasTlax 2026
*/

#ifndef MEM_MAP_H
#define MEM_MAP_H



// RAM (256 byte)
#define RAM_SIZE 256

uint8_t RAM[RAM_SIZE];

#define RAM_START        0x00
#define RAM_END          0x7F

// STACK (16 byte)
#define STACK_START      0x80
#define STACK_END        0x8F

// PROGRAM AREA
#define PROGRAM_START    0x90
#define PROGRAM_END      0xDF

// I/O REGION
#define IO_INPUT         0xF0   // user input
#define IO_OUTPUT        0xF1   // user output
#define IO_STATUS        0xF2   // system status
#define IO_CONTROL       0xF3   // system control
#define IO_CLEAR         0xF4   // clear buffer or screen
#define IO_BUFFER        0xF5   // Access: READ/WRITE
#define IO_DIRECTION     0xF6   // Port way, use with IO_DATA
#define IO_DATA          0xF7   // general line bus
#define IO_TIMER_LOW     0xF8   // 16-bit clock LOW
#define IO_TIMER_HIGH    0xF9   // 16-bit clock HIGH
#define IO_INTERRUPT     0xFA   // INTERRUPT FLAG
#define IO_ENABLE        0xFB   // ENABLE INTERRUPT 
#define IO_DEBUG         0xFC   // debug line
#define IO_RESERVED1     0xFD   // for future updates
#define IO_RESERVED2     0xFE   // for future updates
#define IO_HALT          0xFF   // stop CPU

#endif