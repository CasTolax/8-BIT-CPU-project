/*
	By CasTolax 2026
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "keyboard_interr.h"
#include "../lib/command/ld_a_b.h"

int keyboard_interrupts (int A, int B)
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
        	lda(A);
    	}
    	else if(strcmp(input, "LDB") == 0)
    	{
    		ldb(B);
    	}
    	else if(strcmp(input, "ALU") ==  0)
    	{
    		output_ALU(A,B);
    	}
    	else
    	{
        	printf("Bilinmeyen komut\n");
    	}
	 }


	return 0;
}
