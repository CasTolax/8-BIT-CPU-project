/*
    By Castolax 2026
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "errors.h"

// ALU kütüphanesine erişim için doğru path
#include "../alu/alu.h"

// Zero division hatasını test etmek için yardımcı fonksiyon
// Bu fonksiyon errors.c içinde zaten tanımlanmıştır,
// burada yalnızca test amaçlı kullanıldığından saklanan bir versiyonumuz var.
void test_zero_division(void)
{   
    if(DIV(0,0) == 0){
        print_ERROR("zero division error");
    }
}