/*
	By CasTolax 2026
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdbool.h>

#include "keyboard_interr.h"
#include "../lib/command/ld_a_b.h"
#include "../lib/command/sys_status_command.h"

bool keyboardInterr_active = true;

void keyboard_status(void)
{
	int keyboard_enable = KEYBOARD_TRUE;
	int keyboard_disable = KEYBOARD_FALSE;

	if(keyboard_enable)
	{
		printf("[Keyboard are enable] = 1 \n");
	}
	else if(keyboard_disable)
	{
		printf("[Keyboard are disable] = 0 \n ");
	}

}

int keyboard_interrupts (int A, int B)
{		


	char input[64];
	printf(" \n You can write command right now(exit = 0).\n");

	/*
		keyboard function will be called,
		and when user type someting, the output is like that:
		[Keyboard are enable] = 1
	*/
	keyboard_status();

	 while(1)
	 {	
	 	printf(">");

	 	// out
	 	if(strcmp(input,"0") == 0)
	 		break;



	 	fgets(input, sizeof(input), stdin);

    	// erase the newline
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
    	else if(strcmp(input, "STATUS") == 0)
    	{
    		sys_control();
    	}
    	else
    	{
        	printf("\n");
    	}
	 }


	return 0;
}
