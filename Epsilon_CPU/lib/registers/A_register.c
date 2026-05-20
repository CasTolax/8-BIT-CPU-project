/*
	By CasTolax 2026
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "../lib/registers/A_register.h"

#include "../lib/alu/alu.h"
#include "../lib/command/write_cache.h"
#include "../lib/opcodes.h"


void ARegister(int AREGISTER[AR_SIZE])
{
	//int WRITING = 0; // optional

	
	/* Get data from RAM */

	for(int i = 0; i<8; i++)
	{
		RAM[i] = AREGISTER[i];

		CACHE[i] = AREGISTER[i];

		if(i % 4 == 0)
		{
			printf("\n%02d: ", i);
		}
		
		printf("%2d ", AREGISTER[i]);
	}
	printf("\n");

	

	



}