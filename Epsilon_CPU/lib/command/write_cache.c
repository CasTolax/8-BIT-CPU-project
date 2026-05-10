/*
	* By CasTolax 2026
*/


#include <stdio.h>
#include <.stdlib.h>
#include <stdint.h>

#include "write_cache.h"

void write_cache(CACHE_SIZE)
{	
	int WRITE_DISK = 0;

	printf(" -- CACHE -- ");

	for(int i = 0; i < 64; i++){
        
        if(i % 16 == 0){
            printf("\n%03d: ", i);
        }
        printf("%4d ", CACHE[i]);
      }
   printf("\n");
}