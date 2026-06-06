/*
	By CasTolax
*/


#include <stdint.h>
#include <stdio.h>

#ifndef FLAGS_H
#define FLAGS_H

// adresses
//#define CF 0xf1
//#define ZF 0xf2
//#define OF 0xf3

void CF(int Carry_flag);
void OF(int A, int B);
void ZF(int Zero_flag);

#endif
