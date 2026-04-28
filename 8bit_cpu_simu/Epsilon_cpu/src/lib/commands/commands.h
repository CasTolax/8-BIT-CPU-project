/*
    By CasTolax 2026
*/

#ifndef COMMANDS_H
#define COMMANDS_H

#include "stdint.h"
#include "stdlib.h"

#include "lda.h"
#include "ldb.h"
#include "add.h"
#include "sub.h"
#include "mul.h"
#include "div.h"
#include "mod.h"
#include "hlt.h"

typedef enum {
    LDA = 0x01,
    LDB = 0x02,
    ADD = 0x03,
    SUB = 0x04,
    MUL = 0x05,
    DIV = 0x06,
    MOD = 0x07,
    HLT = 0x0FF
    
} commands;

#endif