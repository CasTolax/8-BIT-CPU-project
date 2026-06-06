/* 
	By CasTolax 2026

	There are just printed A and B.
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "../lib/alu/alu.h"
#include "../lib/sys_status/sys_status.h"

#include "ld_a_b.h" // LDA/LDB header

int lda(int A)
{	
	
	printf("LDA = %d\n",A);
	return 0;
}

int ldb(int B)
{	
	printf("LDB = %d\n",B);
	return 0;
}

int output_ALU(int A, int B)
{	
	printf("ADD[0x01] = %d\n",ADD(A,B));
	printf("SUB[0x02] = %d\n",SUB(A,B));
	printf("MUL[0x03] = %d\n",MUL(A,B));
	printf("DIV[0x04] = %d\n",DIV(A,B));

	return 0;
}

int sys_control(void)
{	
	printf("STATUS[0xBe1]: \n");
	printf("%d\n",status_ALU());
	printf("%d\n",status_CLOCK());
	printf("%d\n",status_INTERRUPTS());
	return 0;
}