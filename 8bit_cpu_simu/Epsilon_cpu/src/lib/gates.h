/*
    * gates.h : this is the gates lib. We have a not,and,or,xor,nand,nor,xnor gates...
    * By CasTolax 2026
*/

#ifndef GATES_H
#define GATES_H

// 1 = 0 / 0 = 1
static inline int NOT_GATE(int a) 
{
    return(a == 1) ? 0:1; 
} 

// 0,0 = 0 / 1,0 = 0 / 0,1 = 0 / 1,1 = 1
static inline int AND_GATE(int a, int b) 
{
    return(a == 1 && b == 1) ? 1:0;
}

// 0,0 = 0 / 1,0 = 1 / 0,1 = 1 / 1,1 = 1
static inline int OR_GATE(int a, int b)
{
    return (a == 1 || b == 1) ? 1:0;
}

// 0,0 = 0 / 1,0 = 1 / 0,1 = 1 / 1,1 = 0
static inline int XOR_GATE(int a,int b)
{
    return (a != b) ? 1:0;
}

// 0,0 = 1 / 1,0 = 1 / 0,1 = 1 / 1,1 = 0
static inline int NAND_GATE(int a, int b)
{
    return NOT_GATE(AND_GATE(a,b));
}

// 0,0 = 1 / 1,0 = 0 / 0,1 = 0 / 1,1 = 0
static inline int NOR_GATE(int a, int b)
{
    return NOT_GATE(OR_GATE(a,b));
}

// 0,0 = 1 / 1,0 = 0 / 0,1 = 0 / 1,1 = 1
static inline int XNOR_GATE(int a, int b)
{
    return NOT_GATE(XOR_GATE(a,b));
}
#endif