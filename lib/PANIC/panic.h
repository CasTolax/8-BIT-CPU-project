/*
	By CasTolax 2026

	This section will contain code designed to protect the processor's limits.

It will include information on memory size, cache size, processing limits,
and various error-handling mechanisms. If the number of operations exceeds 3,
the system will display a panic message and shut down.
*/

#include <stdint.h>
#include <stdio.h>

#ifndef PANIC_H
#define PANIC_H

/*
	Specifically, if anyone exceeds the limit here,
    it will automatically shut down and, depending on the system’s status,
    either restart or pause temporarily.
    Actually, this resembles the scheduler logic, but without it,
    I don’t plan on implementing a scheduler.
*/
typedef struct 
{
	uint8_t RAM_HANDLING;
	uint8_t CACHE_HANDLING;
	uint8_t ALU_HANDLING;
	uint8_t INTERRUPTS_HANDLING;

}panic_datas_cpu_t;


int sys_control_handling(int A,int B);

#endif
