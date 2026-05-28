/*
	By CasTolax 2026
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../lib/PANIC/panic.h"
#include "../lib/alu/alu.h"
#include "../lib/interrupts/keyboard_interr.h"
#include "../lib/command/write_cache.h"
#include "../lib/err/errors.h"
#include "../lib/opcodes.h"
#include "../lib/clock.h"

uint8_t sys_control_handling(void)
{
    uint8_t cores[10];
    memset(cores, 0, sizeof(cores));

    panic_datas_cpu_t p = {0};

    /* RAM CONTROL */
    if (RAM[RAM_SIZE - 1] == 255)
    {
        p.RAM_HANDLING = 1;
        cores[0] = 1;

        memory_overflow_error();
        clock_cycle();
        RAM_RESET();

        print_ERROR("RAM OVERFLOW ERROR[0x0ddf]");
        printf("RAM ERROR\n");
        fflush(stdout);

        return p.RAM_HANDLING;
    }

    /* CACHE CONTROL */
    if (CACHE[CACHE_SIZE - 1] == 64)
    {
        p.CACHE_HANDLING = 1;
        cores[1] = 1;

        cache_overflow_error();
        clock_cycle();

        print_ERROR("CACHE OVERFLOW ERROR[0x0AAf]");
        printf("CACHE ERROR\n");
        fflush(stdout);

        return p.CACHE_HANDLING;
    }

    
    return 0;
}