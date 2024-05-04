#ifndef Complexvect_h
#define Complexvect_h

#include <stdio.h>
#include <stdlib.h>

struct compl{
    double a;
    double mn;
};
void* sumofcomplex(void* x, void* y);
void* differenceofcomplex(void* x, void* y);
void* negativecomplex(void* x);
void* productofcomplex(void* x, void* y);
void* zerocomplex();
void* complexunit();
#endif 
