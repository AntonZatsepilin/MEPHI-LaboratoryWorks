#include "Doublevect.h"
#include <stdlib.h>
void* sumofdouble(void* x, void* y){
    double* a = (double*)x;
    double* b = (double*)y;
    double* sum = malloc(sizeof(double*));
    *sum = *a + *b;
    return (void*) sum;
}

void* differenceofdouble(void* x, void* y){
    double* a = (double*)x;
    double* b = (double*)y;
    double* sum = malloc(sizeof(double*));
    *sum = *a - *b;
    return (void*) sum;
}


void* negativedouble(void* x){
    double* a = (double*)x;
    double* minus = malloc(sizeof(double*));
    *minus = (-1) * *a;
    return (void*) minus;
}

void* productofdouble(void* x, void* y){
    double* a = (double*)x;
    double* b = (double*)y;
    double* proiz = malloc(sizeof(double*));
    *proiz = *a * *b;
    return (void*) proiz;
}

void* zerodouble() {
    double* n = malloc(sizeof(double*));
    *n = 0;
    return (void*) n;
}

void* doubleunit(){
    double* n = malloc(sizeof(double*));
    *n = 1;
    return (void*) n;
}

