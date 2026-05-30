/*
    By CasTolax
*/
#include "../lib/PANIC/cpu_loop.h"
#include "../src/cpu.h"
#include "../lib/err/errors.h"
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int cpu_run(void)
{   
    int reboot_count = 0;
    char input[64];

    while(1)
    {
        printf("> ");
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL) continue;
        input[strcspn(input, "\n")] = 0;

        printf("[DEBUG] Girilen: '%s'\n", input);
        fflush(stdout);

        if (strcmp(input, "REBOOT") == 0)
        {
            reboot_count++;
            if(reboot_count > MAX_REBOOT)
            {   
                print_ERROR("MAX REBOOT REACHED\n");
                break;
            }
            printf("[REBOOT #%d] CPU restarting...\n", reboot_count);
            fflush(stdout);
            CPU_MAIN();
        }
        else if (strcmp(input, "HALT") == 0)
        {
            cpu.halted = true;
            printf("[HALT] CPU stopped.\n");
            fflush(stdout);
            break;
        }
        else
        {   
            printf("[INFO] Bilinmeyen komut: '%s'\n", input);
            fflush(stdout);
        }
    }
    return 0;
}

int cpu_reboot(void)
{
    cpu.halted       = true;
    cpu.boot_address = 0x0000;
    cpu.opcode       = 0;
    return 0;
}