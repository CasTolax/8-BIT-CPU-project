/*
    errors.c - error handling implementation for Epsilon CPU
    By CasTolax 2026
*/

#include <stdio.h>
#include <stdlib.h>
#include "errors.h"

// Sıfıra bölme hatası
// Kesir hesaplamalarında bölen sıfır olduğunda bu fonksiyon çağrılır.
void zero_division_error(void) {
    fprintf(stderr, "ERROR: Division by zero!\n");
    exit(EXIT_FAILURE);
}

// Geçersiz işlem hatası
// CPU geçersiz bir işlem kodu çalıştırmaya çalışırsa bu fonksiyon çağrılır.
void invalid_process_error(void) {
    fprintf(stderr, "ERROR: Invalid process/instruction!\n");
    exit(EXIT_FAILURE);
}

// Bellek taşması hatası
// RAM'in sınırı aşılırsa bu fonksiyon çağrılır.
void memory_overflow_error(void) {
    fprintf(stderr, "ERROR: Memory overflow!\n");
    exit(EXIT_FAILURE);
}
