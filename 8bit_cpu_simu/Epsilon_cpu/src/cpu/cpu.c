/*  
    By CasTolax 2026
*/

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "Epsilon_cpu/src/lib/clock.h"
#include "Epsilon_cpu/src/lib/gates.h"
#include "Epsilon_cpu/src/lib/mem_map.h"
#include "Epsilon_cpu/src/lib/opcodes_map.h"
#include "Epsilon_cpu/src/lib/commands/commands.h"
#include "Epsilon_cpu/src/lib/alu.h"
#include "Epsilon_cpu/src/lib/commands/write.h"
#include "Epsilon_cpu/src/lib/commands/hlt.h"
#include "Epsilon_cpu/src/lib/commands/lda.h"
#include "Epsilon_cpu/src/lib/commands/ldb.h"
#include "Epsilon_cpu/src/lib/commands/read.h"
#include "Epsilon_cpu/src/lib/commands/push.h"

int cpu_main(void)
{
    // loop + control
    
    while (SLEEP(1));
    {
        switch (commands)
        {
           // There someting is wrong, I am not sure about that!
        case LDA:
            ADD = RAM[PC++];
            AR = RAM[ADD];
            break;
        
        default:
            break;
        }
    }
    
}
