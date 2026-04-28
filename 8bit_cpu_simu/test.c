
/*
    * By CasTolax 2026
*/

#include "Epsilon_cpu/src/lib/clock.h"
#include "Epsilon_cpu/src/lib/gates.h"
#include "Epsilon_cpu/src/lib/add.h"
#include "Epsilon_cpu/src/lib/sub.h"
#include "Epsilon_cpu/src/lib/mul.h"
#include "Epsilon_cpu/src/lib/div.h"
#include "Epsilon_cpu/src/lib/mod.h"
#include "Epsilon_cpu/src/lib/alu.h"
#include "Epsilon_cpu/src/lib/bits/add_bin.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void esc(void); // exit func

/* -- test functions -- */
uint8_t gate_test(uint8_t a, uint8_t b);
uint8_t alu_test(uint8_t a, uint8_t b);
uint8_t add_bin_test(void);

/*-- Main function --*/
int main(void)
{   
    atexit(esc); // exit func
    uint8_t a,b;
    
   while (1)
    {   
        gate_test(a,b);
        
        alu_test(a,b);
    }
    
    return 0;
}

uint8_t gate_test(uint8_t a, uint8_t b)
{
    printf("a = ");
    scanf("%d",&a);
    
    printf("b = ");
    scanf("%d",&b);
    

    int test_1 = NOT_GATE(a);
    int test_2 = AND_GATE(a,b);
    int test_3 = OR_GATE(a,b);
    int test_4 = XOR_GATE(a,b);
    int test_5 = NAND_GATE(a,b);
    int test_6 = NOR_GATE(a,b);
    int test_7 = XNOR_GATE(a,b);

    printf("not gate = %d\n",test_1);
    printf("and gate = %d\n",test_2);
    printf("or gate = %d\n",test_3);
    printf("xor gate = %d\n",test_4);
    printf("nand gate = %d\n",test_5);
    printf("nor gate = %d\n",test_6);
    printf("xnor gate = %d\n",test_7);

    printf("---------------------------------- \n");
    printf("TEST OK!\n");

}

uint8_t alu_test(uint8_t a, uint8_t b)
{
    printf(" -- ALU TEST -- \n");
    
    printf("a = \n");
    scanf("%d",&a);

    printf("b = \n");
    scanf("%d",&b);
    

    printf("add result = %d\n",add(a,b));
    printf("sub result = %d\n",sub(a,b));
    printf("mul result = %d\n",mul(a,b));
    printf("div result = %d\n",dıv(a,b));
    printf("mod result = %d\n",mod(a,b));
    
    printf("ALU TEST OK!\n");


    printf(" -- ALU BİN TEST -- \n");

    
}

uint8_t add_bin_test(void)
{
    return 0;
}

// exit
void esc(void)
{
    printf("Exit succesfuly \n");
}