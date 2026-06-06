/*
	By CasTolax 2026
*/

#include <stdint.h>
#include <stdio.h>

#include "../lib/registers/Fregisters/flags.h"


void OF(int A, int B)
{
	int result = A + B;

	if(result > 127)
	{
		printf("positive overflow![OF] %d\n", result);
	}
	else if(result < -128)
	{
		printf("negative overflow![OF] %d\n", result);
	}
}