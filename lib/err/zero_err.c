/*
    By Castolax 2026
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "errors.h"

#include "../alu/alu.h"

// Helper function to test for division by zero
// This function is already defined in errors.c;
// since it is used here solely for testing purposes, we have a separate version.
void test_zero_division(void)
{   
    if(DIV(0,0) == 0){
        print_ERROR("zero division error");
    }
}