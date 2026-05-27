/*
	By CasTolax 2026
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "../src/cpu.h"
#include "../lib/alu/alu.h"

void ZF(int Zero_flag)
{

	// very basic one.
	
		if(Zero_flag == 0)
	{	

		printf("[ALU] ZF = 1\n");
	}
	else
	{	
		Zero_flag = 1;
		printf("[ALU] ZF = 0\n");
	}
}
	

	