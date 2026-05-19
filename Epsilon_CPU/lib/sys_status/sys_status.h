/*
	By CasTolax
*/

#ifndef SYS_STATUS_H
#define SYS_STATUS_H

#define SYS_TRUE  1 // when the system enable
#define SYS_FALSE 0 // or disable


typedef struct
{
	int enable_ALU, disable_ALU;
	int enable_CLOCK, disable_CLOCK;
	int enable_INTERRUPTS, disable_INTERRUPTS;
	int enable_COMMAND, enable_COMMAND; 

}SYS_Status;

// check ALU and other process
void status_ALU(void);

// chech timer or clock...
void status_CLOCK(void);

// control ınterrupts to keyboard_interrupts
void status_INTERRUPTS(void);

//check the command 
void status_COMMAND(void);

#endif