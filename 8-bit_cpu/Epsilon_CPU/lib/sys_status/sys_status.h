/*
	By CasTolax
*/

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef SYS_STATUS_H
#define SYS_STATUS_H

#define SYS_TRUE  1 // when the system enable
#define SYS_FALSE 0 // or disable

typedef struct
{
	int A;
	int B;

	bool status_false;
	bool status_true;

}SYS;

// check ALU and other process
int status_ALU(void);

// chech timer or clock...
int status_CLOCK(void);

// control ınterrupts to keyboard_interrupts
int status_INTERRUPTS(void);

//check the command 
int status_COMMAND(void);

// main 
int status_main(void);

#endif