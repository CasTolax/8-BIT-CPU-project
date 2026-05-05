/*
    errors.h - error handling for Epsilon CPU
    By CasTolax 2026
*/

#ifndef ERRORS_H
#define ERRORS_H


#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// when calculations is divided with zero, this function will be called.
void zero_division_error(void);

void invalid_process_error(void);

void memory_overflow_error(void);

// Hata mesajını ekrana yazdır. Bu fonksiyon static inline olarak
// tanımlandığı için birden fazla dosyada include edilse bile hata oluşmaz.
static inline void print_ERROR(const char* error_message){
    printf("ERROR: %s\n", error_message);
}



#endif