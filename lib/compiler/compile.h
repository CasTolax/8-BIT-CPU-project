/*
    By CasTolax 2026
*/

#ifndef COMPILE_H
#define COMPILE_H

#define AREA 256

extern char AREA_SIZE[AREA];

extern int COMPILER_STATUS;
extern int COMPILER_FINISH;
extern int COMPILER_RUNNING;

typedef enum
{
    VARIABLE,
    PROCESS,
    OPERATORS,
    INTEGER,
    STRING,
    OK,
    UNKNOWN
} TOKEN_TYPE;

typedef struct 
{
    TOKEN_TYPE type;
    char text[64];
} Token;

int parser(void);

#endif