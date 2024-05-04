#include "Testprog.h"
#include "Vrctor3.h"
#include "Doublevect.h"
#include "RingInfo.h"
#include "Complexvect.h"
int testofdouble(double x, double y, double z,double x2, double y2, double z2, double rx, double ry, double rz){
    struct RingInfo* ringInfodouble = Create(sizeof(double), sumofdouble ,differenceofdouble, zerodouble, negativecomplex, productofcomplex, doubleunit);
    struct Vector3 *a = malloc(sizeof(struct Vector3));
    struct Vector3 *b = malloc(sizeof(struct Vector3));
    struct Vector3 *r = malloc(sizeof(struct Vector3));
    a->x = &x;
    a->y = &y;
    a->z = &z;
    b->x = &x2;
    b->y = &y2;
    b->z = &z2;
    
    r->x = &rx;
    r->y = &ry;
    r->z = &rz;
    
    
    a->ringInfo = ringInfodouble;
    b->ringInfo = ringInfodouble;
    r->ringInfo = ringInfodouble;
    int k = 0;
    r = Sumvect(a, b);
    if(*(double*)r->x == rx, *(double*)r->y == ry, *(double*)r->z == rz) k+=1;
    r = Negativevect(a);
    if(*(double*)r->x == rx, *(double*)r->y == ry, *(double*)r->z == rz) k+=1;
    r = Differencevect(a, b);
    if(*(double*)r->x == rx, *(double*)r->y == ry, *(double*)r->z == rz) k+=1;
    r = Scalarproduct(a, b);
    if(*(double*)r->x == rx) k+=1;
    r = Mixedproductvect(a, b);
    if(*(double*)r->x == rx, *(double*)r->y == ry, *(double*)r->z == rz) k+=1;
    free(a);
    free(b);
    free(r);
    if(k >= 1){
        return 0;
    }else{
        return 1;
    }
}


int testofcomplex(struct compl x3, struct compl y3, struct compl z3, struct compl x4, struct compl y4, struct compl z4, struct compl rx, struct compl ry, struct compl rz){
    struct RingInfo* ringInfocomplex = Create(sizeof(struct compl), sumofcomplex, differenceofcomplex, zerocomplex, negativecomplex, productofcomplex, complexunit);
    struct Vector3 *a1 = malloc(sizeof(struct Vector3));
    struct Vector3 *b1 = malloc(sizeof(struct Vector3));
    struct Vector3 *c1 = malloc(sizeof(struct Vector3));
    a1->x = &x3;
    a1->y = &y3;
    a1->z = &z3;
    b1->x = &x4;
    b1->y = &y4;
    b1->z = &z4;
    a1->ringInfo = ringInfocomplex;
    b1->ringInfo = ringInfocomplex;
    c1->ringInfo = ringInfocomplex;
    int k = 0;
    c1 = Sumvect(a1, b1);
    if(((struct compl*)c1->x)->a == rx.a && ((struct compl*)c1->x)->mn == rx.mn && ((struct compl*)c1->y)->a == ry.a && ((struct compl*)c1->y)->mn == ry.mn && ((struct compl*)c1->z)->a == rz.a && ((struct compl*)c1->z)->mn == rz.mn) k+=1;
    c1 = Negativevect(a1);
    if(((struct compl*)c1->x)->a == rx.a && ((struct compl*)c1->x)->mn == rx.mn && ((struct compl*)c1->y)->a == ry.a && ((struct compl*)c1->y)->mn == ry.mn && ((struct compl*)c1->z)->a == rz.a && ((struct compl*)c1->z)->mn == rz.mn) k+=1;
    c1 = Differencevect(a1, b1);
    if(((struct compl*)c1->x)->a == rx.a && ((struct compl*)c1->x)->mn == rx.mn && ((struct compl*)c1->y)->a == ry.a && ((struct compl*)c1->y)->mn == ry.mn && ((struct compl*)c1->z)->a == rz.a && ((struct compl*)c1->z)->mn == rz.mn) k+=1;
    c1 = Scalarproduct(a1, b1);
    if(((struct compl*)c1->x)->a == rx.a && ((struct compl*)c1->x)->mn == rx.mn && ((struct compl*)c1->y)->a == ry.a && ((struct compl*)c1->y)->mn == ry.mn && ((struct compl*)c1->z)->a == rz.a && ((struct compl*)c1->z)->mn == rz.mn) k+=1;
    c1 = Mixedproductvect(a1, b1);
    if(((struct compl*)c1->x)->a == rx.a && ((struct compl*)c1->x)->mn == rx.mn && ((struct compl*)c1->y)->a == ry.a && ((struct compl*)c1->y)->mn == ry.mn && ((struct compl*)c1->z)->a == rz.a && ((struct compl*)c1->z)->mn == rz.mn) k+=1;
    free(a1);
    free(b1);
    free(c1);
    if(k >= 1){
        return 0;
    }else{
        return 1;
    }
}
