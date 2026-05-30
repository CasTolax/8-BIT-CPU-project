/*
    By CasTolax 2026
*/
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../src/cpu.h"
#include "keyboard_interr.h"
#include "../lib/command/ld_a_b.h"
#include "../lib/command/sys_status_command.h"
#include "../lib/alu/alu.h"
#include "../lib/registers/A_register.h"
#include "../lib/registers/Fregisters/flags.h"
#include "../lib/PANIC/panic.h"
#include "../lib/PANIC/cpu_loop.h"

bool keyboardInterr_active = true;
extern int zero_flag;

void keyboard_status(void)
{
    int keyboard_enable = KEYBOARD_TRUE;
    int keyboard_disable = KEYBOARD_FALSE;
    if (keyboard_enable)
        printf("[Keyboard enabled] = 1\n");
    else if (keyboard_disable)
        printf("[Keyboard disabled] = 0\n");
}

int input_interr(int value_1, int value_2)
{
    int values[10] = {0};
    keyboard_status();
    printf("Scanning inputs...\n");
    scanf("%d", &value_1);
    scanf("%d", &value_2);
    // buffer temizle
    int c; while ((c = getchar()) != '\n' && c != EOF);
    values[0] = value_1;
    values[1] = value_2;
    for (int i = 0; i < 10; i++)
        printf("%d ", values[i]);
    printf("\n");
    return 0;
}

int keyboard_interrupts(int A, int B)
{   
    char input[64];
    printf("\nYou can write command right now (exit = 0).\n");
    keyboard_status();

    while (1)
    {
        printf("> ");
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL)
            break;

        input[strcspn(input, "\n")] = 0;

    
        if (strcmp(input, "LDA") == 0)
        {
            lda(A);
        }
        else if (strcmp(input, "LDB") == 0)
        {
            ldb(B);
        }
        else if (strcmp(input, "ALU") == 0)
        {
            output_ALU(A, B);
        }
        else if (strcmp(input, "STATUS") == 0)
        {
            sys_control();
        }
        else if (strcmp(input, "INPUT VALUE") == 0)
        {
            int value1 = 0, value2 = 0;
            input_interr(value1, value2);
        }
        else if (strcmp(input, "RAM RESET") == 0)
        {
            RAM_RESET();
        }
        else if (strcmp(input, "FLAGS") == 0)
        {
            CF(A);
            CF(B);
            OF(A, B);
            ZF(ADD(A, B));
            ZF(SUB(A, B));
            ZF(MUL(A, B));
            ZF(DIV(A, B));
        }
        else if (strcmp(input, "PANIC CONTROL") == 0)
        {
            sys_control_handling(A, B);
        }
        else if (strcmp(input, "REBOOT") == 0)
        {
            // buffer temizle, sonra cpu_run'a geç
            cpu_run();
            // cpu_run'dan döndükten sonra (HALT yapıldıysa) buradan da çık
            if (cpu.halted) break;
        }
        else if (strcmp(input, "HALT") == 0)
        {
            cpu.halted = true;
            printf("[HALT] CPU STOPPED\n");
            break;
        }
        else if(strcmp(input, "0") == 0)
        {
            break;
        }
        else
        {
            printf("[INFO] Bilinmeyen komut: '%s'\n", input);
        }
    }
    return 0;
}
