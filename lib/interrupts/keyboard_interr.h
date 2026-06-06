/* 
	By CasTolax 2026
*/

#include <stdint.h>
#include <stdbool.h>

#ifndef KEYBOARD_INTERR_H
#define KEYBOARD_INTERR_H

#define KEYBOARD_TRUE 1
#define KEYBOARD_FALSE 0

extern bool keyboardInterr_active;

int keyboard_interrupts (int A,int B);
void keyboard_status(void);

/* for ALU and others 2 values */
int input_interr(int value1, int value2);

#endif

