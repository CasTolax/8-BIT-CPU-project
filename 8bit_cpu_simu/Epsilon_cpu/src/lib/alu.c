/*
    * By CasTolax 2026
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "alu.h"

#include "add.h"
#include "sub.h"
#include "div.h"
#include "mul.h"
#include "mod.h"

#include "gates.h"
#include "opcodes_map.h"
#include "mem_map.h"
#include "clock.h"
#include "Epsilon_cpu/src/lib/err.h"
#include "Epsilon_cpu/src/lib/commands/commands.h"

uint8_t alu_main(void)
{
    switch (DIV(A,B))
    {
    case 0:
        err_ZERO();
        continue;;
    case NULL:
        err_NULL();
        continue;
    default:
        break;
    }

    
}


