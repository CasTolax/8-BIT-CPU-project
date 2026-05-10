/*
    *By CasTolax 2026
*/

#ifndef CPU_H
#define CPU_H

#include <stdint.h>
/* main function */
int CPU_MAIN(void);
/* error handling for CPU */
int cpu_error(void);

// scheduler
int scheduler_cpu(void);

#endif
