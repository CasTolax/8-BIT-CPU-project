/*
	By CasTolax 2026
*/

#ifndef GATES_H
#define GATES_H

#include <stdint.h>
#include <stdio.h>

int not_gate(int a) {return(a==1)?0:1;} // 1 = 0 / 0 = 1

int and_gate(int a,int b){return(a==1 && b==1)?1:0;} // 0,0 = 0 / 1,0 = 0 / 0,1 = 0 / 1,1 = 1

int or_gate(int a,int b){return(a==1 || b==1)?1:0;} // 0,0 = 0 / 1,0 = 1 / 0,1 = 1 / 1,1 = 1

int xor_gate(int a,int b){return(a!=b)?1:0;} // 0,0 = 0 / 1,0 = 1 / 0,1 = 1 / 1,1 = 0

int nand_gate(int a,int b){return not_gate(and_gate(a,b));} // 0,0 = 1 / 1,0 = 1 / 0,1 = 1 / 1,1 = 0

int nor_gate(int a,int b){return not_gate(or_gate(a,b));} // 0,0 = 1 / 1,0 = 0 / 0,1 = 0 / 1,1 = 0

int xnor_gate(int a,int b ){return not_gate(xor_gate(a,b));}// 0,0 = 1 / 1,0 = 0 / 0,1 = 0 / 1,1 = 1


#endif