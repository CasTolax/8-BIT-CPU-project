/*
	By CasTolax 2026
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "keyboard_interr.h"

int keyboard_interrupts (void)
{	
	char input[64];
	printf(" \n You can write command right now(exit = 0).\n");

	 while(1)
	 {	
	 	// out
	 	if(strcmp(input,"0") == 0)
	 		break;


	 	fgets(input, sizeof(input), stdin);

    	// newline kaldır
    	input[strcspn(input, "\n")] = 0;

    	if (strcmp(input, "LDA") == 0)
    	{
        	printf("LDA komutu \n");
    	}
    	else
    	{
        	printf("Bilinmeyen komut\n");
    	}
	 }


	return 0;
}
