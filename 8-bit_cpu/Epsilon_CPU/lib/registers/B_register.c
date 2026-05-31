/*
    By CasTolax 2026

     B REGISTER
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "../lib/registers/B_register.h"
#include "../lib/registers/A_register.h"
#include "../lib/alu/alu.h"
#include "../lib/command/write_cache.h"
#include "../lib/opcodes.h"
#include "../lib/clock.h"

void BWait(int index, int BREGISTER[BR_SIZE]);

void BRegister(int BREGISTER[BR_SIZE])
{
    /* Transfer data */
    for (int i = 0; i < BR_SIZE; i++)
    {
        RAM[i] = BREGISTER[i];
        CACHE[i] = BREGISTER[i];
    }

    /* Print register contents */
    printf("B REGISTER:\n");

    for (int i = 0; i < BR_SIZE; i++)
    {
        if (i % 4 == 0)
        {
            printf("\n%02d: ", i);
        }

        printf("%2d ", BREGISTER[i]);
    }

    printf("\n");

    /* Simulate register lifecycle */
    for (int i = 0; i < BR_SIZE; i++)
    {
        AWait(i, BREGISTER);
    }
}

void BWait(int index, int BREGISTER[BR_SIZE])
{
   
    if (index < (BR_SIZE / 2))
    {
        BREGISTER[index] = 0;
    }
    else
    {
        clock_cycle();
    }
}