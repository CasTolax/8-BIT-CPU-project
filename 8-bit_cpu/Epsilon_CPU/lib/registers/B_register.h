/*
	By CasTolax 2026
*/

#ifndef B_REGISTER_H
#define B_REGISTER_H

#include <stdio.h>
#include <stdint.h>

#define BR_SIZE 8
extern int BR[BR_SIZE];

void BRegister(int BREGISTER[BR_SIZE]);
void BWait(int index, int BREGISTER[BR_SIZE]);

#endif