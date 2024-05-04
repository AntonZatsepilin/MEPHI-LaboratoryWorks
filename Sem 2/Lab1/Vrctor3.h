#define Vrctor3_h
#include "Doublevect.h"
#include <stdlib.h>
#include <stdio.h>
#include "RingInfo.h"
#include "Complexvect.h"

struct Vector3{
    struct RingInfo* ringInfo;
    void* x;
    void* y;
    void* z;
};

struct Vector3* Sumvect(struct Vector3* v1, struct Vector3* v2);
struct Vector3* Negativevect(struct Vector3* v1);
struct Vector3* Scalarproduct(struct Vector3* v1, struct Vector3* v2);
struct Vector3* Differencevect(struct Vector3* v1, struct Vector3* v2);
struct Vector3* Mixedproductvect(struct Vector3* v1, struct Vector3* v2);
