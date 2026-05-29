/*
	By CasTolax 2026

    I solve this shit bugs and errors.
    thanks cloude!
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

int sys_control_handling(int A,int B)
{
    uint8_t cores[10];
    memset(cores, 0, sizeof(cores));
    panic_datas_cpu_t p = {0};

    /* RAM CONTROL */
    int ram_full = 1;
    for (int i = 0; i < RAM_SIZE; i++) {
        if (RAM[i] == 0) { ram_full = 0; break; }
    }

    if (ram_full)
    {
        p.RAM_HANDLING = 1;
        cores[0] = 1;
        memory_overflow_error();
        clock_cycle();
        RAM_RESET();
        print_ERROR("RAM OVERFLOW ERROR[0x0ddf]");
        printf("RAM ERROR\n");
        fflush(stdout);
    }

    /* CACHE CONTROL */
    int cache_full = 1;
    for (int i = 0; i < CACHE_SIZE; i++) {
        if (CACHE[i] == 0) { cache_full = 0; break; }
    }

    if (cache_full)
    {
        p.CACHE_HANDLING = 1;
        cores[1] = 1;
        cache_overflow_error();
        clock_cycle();
        print_ERROR("CACHE OVERFLOW ERROR[0x0AAf]");
        printf("CACHE ERROR\n");
        fflush(stdout);
    }

    /* this is the debuging*/
    printf("[PANIC CTRL] RAM_HANDLING=%d | CACHE_HANDLING=%d\n",
           p.RAM_HANDLING, p.CACHE_HANDLING);
    fflush(stdout);

    if (p.RAM_HANDLING) return p.RAM_HANDLING;
    if (p.CACHE_HANDLING) return p.CACHE_HANDLING;

    /* control the ALU functions */
    if(ADD(A,B) > OVERFLOW_LIMIT)
    {
        printf("ADD OVERFLOW[0x01]\n");
        print_ERROR("CHECK THE INPUT");
        invalid_process_error();
    }
    if(SUB(A,B) > OVERFLOW_LIMIT)
    {
        printf("SUB OVERFLOW[0x02]\n");
        print_ERROR("CHECK THE INPUT");
        invalid_process_error();
    }
    if(MUL(A,B) > OVERFLOW_LIMIT)
    {
        printf("MUL OVERFLOW[0x03]\n");
        print_ERROR("CHECK THE INPUT");
        invalid_process_error();
    }
    if(DIV(A,B) > OVERFLOW_LIMIT)
    {
        printf("DIV OVERFLOW[0x04]\n");
        print_ERROR("CHECK THE INPUT");
        invalid_process_error();
    }
    

    return 0;
}
