/*
	* By CasTolax 2026
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "write_cache.h"
#include "../lib/alu/alu.h"
#include "../lib/opcodes.h"

int CACHE[CACHE_SIZE] = {0};

int write_cache(int write_process[CACHE_SIZE])
{	

    printf("\n Cache is ready to read... \n");

	printf("\n -- CACHE -- \n");

	for(int i = 0; i<64; i++)
    {   
        RAM[i] = write_process[i];

        if(i % 8 == 0)
        {
            printf("\n%02d: ",i);
        }
        printf("%2d ",write_process[i]);
    }
    printf("\n\n");

    return 0;
}