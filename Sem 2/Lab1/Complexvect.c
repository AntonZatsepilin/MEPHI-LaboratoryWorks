#include "Complexvect.h"
void* sumofcomplex(void* x, void* y){
    struct compl*a = (struct compl*)x;
    struct compl*b = (struct compl*)y;
    struct compl* sum = malloc(sizeof(struct compl*));
    sum->a = a->a + b->a;
    sum->mn = a->mn + b->mn;
    return (void*) sum;
}

void* differenceofcomplex(void* x, void* y){
    struct compl*a = (struct compl*)x;
    struct compl*b = (struct compl*)y;
    struct compl* sum = malloc(sizeof(struct compl*));
    sum->a = a->a - b->a;
    sum->mn = a->mn - b->mn;
    return (void*) sum;
}


void* negativecomplex(void* x){
    struct compl*a = (struct compl*)x;
    struct compl* minus = malloc(sizeof(struct compl*));
    minus->a = (-1)*(a->a);
    minus->mn = (-1)*(a->mn);
    return (void*) minus;
}

void* productofcomplex(void* x, void* y){
    struct compl*a = (struct compl*)x;
    struct compl*b = (struct compl*)y;
    struct compl* proizv = malloc(sizeof(struct compl*));
    proizv->a = a->a * b->a;
    proizv->mn = a->mn * b->mn;
    return (void*) proizv;
}

void* zerocomplex(){
    struct compl* n = malloc(sizeof(double*));
    n->a = 0;
    n->mn = 0;
    return (void*) n;
}

void* complexunit(){
    struct compl* n = malloc(sizeof(double*));
    n->a = 1;
    n->mn = 1;
    return (void*) n;
}
