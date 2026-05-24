/*
	By CasTolax

	* This is a simple control mechanism. As a result,
	* it doesn’t actually controlthat many things.
*/

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#include "../lib/command/ld_a_b.h"
#include "../lib/command/write_cache.h"
#include "../lib/alu/alu.h"
#include "../lib/clock.h"
#include "../lib/interrupts/keyboard_interr.h"

#include "../lib/sys_status/sys_status.h"

int status_ALU(void)
{	
	//SYS s;

	// check the cpu.c -> 80-81
	//s.A = 22;
	//s.B = 5;

	if(alu_active ==  true)
	{
		alu_active = true;
		printf("Status: ALU OK! %d\n",alu_active);
	}
	else
	{
		alu_active = false;
		printf("Status: ALU FALSE! %d\n",alu_active);
	}

	return alu_active ? 1:0;


}

// chech timer or clock...
int status_CLOCK(void)
{
	if(clock_active == true)
	{
		clock_active = true;
		printf("Status: CLOCK OK! %d\n",clock_active); 
	}
	else
	{
		clock_active = false;
		printf("Status: CLOCK FALSE! %d\n", clock_active);
	}

	return clock_active ? 1:0;
}

// control ınterrupts to keyboard_interrupts
int status_INTERRUPTS(void)
{
	if(keyboardInterr_active == true)
	{
		printf("Status: KEYBOARD AND INTERRUPT OK! %d\n",keyboardInterr_active);
	}
	else
	{
		keyboardInterr_active = false;
		printf("Status: KEYBOARD AND INTERRUPT FALSE! %d\n", keyboardInterr_active);
	}

	return keyboardInterr_active ? 1:0;
}	


// main function
int status_main(void)
{	
	status_ALU();
	status_CLOCK();
	status_INTERRUPTS();
	return 0;

}