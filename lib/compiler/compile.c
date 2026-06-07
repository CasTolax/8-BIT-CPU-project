/*
    By CasTolax 2026
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../lib/compiler/compile.h"

int COMPILER_STATUS = 0;
int COMPILER_FINISH = 0;
int COMPILER_RUNNING = 0;

char AREA_SIZE[AREA];

static int is_keyword(const char *s)
{
    return strcmp(s, "int") == 0;
}

/* TOKEN PRINT */
static void print_token(Token t)
{
    printf("TOKEN: %-10d TEXT: %s\n", t.type, t.text);
}

/* LEXER */
static void lexer(char *line)
{
    Token token;
    int i = 0;

    while (line[i] != '\0')
    {
        /* boşluk */
        if (isspace(line[i]))
        {
            i++;
            continue;
        }

        /* NUMBER */
        if (isdigit(line[i]))
        {
            int j = 0;
            while (isdigit(line[i]))
            {
                token.text[j++] = line[i++];
            }
            token.text[j] = '\0';
            token.type = INTEGER;
            print_token(token);
            continue;
        }

        /* IDENTIFIER / KEYWORD */
        if (isalpha(line[i]))
        {
            int j = 0;
            while (isalnum(line[i]))
            {
                token.text[j++] = line[i++];
            }
            token.text[j] = '\0';

            if (is_keyword(token.text))
                token.type = PROCESS;   // int → PROCESS (şimdilik)
            else
                token.type = VARIABLE;

            print_token(token);
            continue;
        }

        /* OPERATORS */
        if (strchr("=+-*/<>!&|;", line[i]))
        {
            token.text[0] = line[i++];
            token.text[1] = '\0';
            token.type = OPERATORS;
            print_token(token);
            continue;
        }

        /* UNKNOWN */
        token.text[0] = line[i++];
        token.text[1] = '\0';
        token.type = UNKNOWN;
        print_token(token);
    }
}

/* PARSER (şimdilik sadece giriş noktası) */
int parser(void)
{
    char line[256];

    printf("Compiler is ready...\n");
    COMPILER_STATUS = 1;

    printf("> ");
    fgets(line, sizeof(line), stdin);

    line[strcspn(line, "\n")] = 0;

    lexer(line);

    COMPILER_FINISH = 1;

    return 0;
}