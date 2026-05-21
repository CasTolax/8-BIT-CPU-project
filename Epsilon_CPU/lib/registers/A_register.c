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
#include "../lib/clock.h"

void AWait(int index, int AREGISTER[AR_SIZE]);

void ARegister(int AREGISTER[AR_SIZE])
{
    /* Transfer data */
    for (int i = 0; i < AR_SIZE; i++)
    {
        RAM[i] = AREGISTER[i];
        CACHE[i] = AREGISTER[i];
    }

    /* Print register contents */
    printf("A REGISTER:\n");

    for (int i = 0; i < AR_SIZE; i++)
    {
        if (i % 4 == 0)
        {
            printf("\n%02d: ", i);
        }

        printf("%2d ", AREGISTER[i]);
    }

    printf("\n");

    /* Simulate register lifecycle */
    for (int i = 0; i < AR_SIZE; i++)
    {
        AWait(i, AREGISTER);
    }
}

void AWait(int index, int AREGISTER[AR_SIZE])
{
    /*
        First half:
        clear temporary register data

        Second half:
        wait clock cycle
    */

    if (index < (AR_SIZE / 2))
    {
        AREGISTER[index] = 0;
    }
    else
    {
        clock_cycle();
    }
}
