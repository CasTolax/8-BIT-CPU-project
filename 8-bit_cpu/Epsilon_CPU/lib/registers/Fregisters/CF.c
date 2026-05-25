/*
	By CasTolax 2026
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "../lib/alu/alu.h"
#include "../src/cpu.h"

void CF(int Carry_flag)
{	
	data d;

	/*
		if you change this, look at the:
		cpu.c file
	*/
	d.A = 22;
	d.B = 5;

	Carry_flag = 0; // disable

	if( (d.A + d.B) > 255)
	{	
		Carry_flag = 1; // enable
		printf("register overflow[CF = 1]%d\n",Carry_flag);
	}
	else
	{
		Carry_flag = 0; // disable
		printf("register[CF = 0]%d\n",Carry_flag);
	}


}
