#include "Vrctor3.h"

struct Vector3* Sumvect(struct Vector3* v1, struct Vector3* v2) {
    struct Vector3* result = malloc(sizeof(struct Vector3));
    result->ringInfo = v1->ringInfo;
    result -> x = result->ringInfo->sum(v1->x, v2->x);
    result -> y = result->ringInfo->sum(v1->y, v2->y);
    result -> z = result->ringInfo->sum(v1->z, v2->z);
    return result;
}

struct Vector3* Differencevect(struct Vector3* v1, struct Vector3* v2) {
    struct Vector3* result = malloc(sizeof(struct Vector3));
    result->ringInfo = v1->ringInfo;
    result -> x = result->ringInfo->difference(v1->x, v2->x);
    result -> y = result->ringInfo->difference(v1->y, v2->y);
    result -> z = result->ringInfo->difference(v1->z, v2->z);
    return result;
}


struct Vector3* Mixedproductvect(struct Vector3* v1, struct Vector3* v2) {
    struct Vector3* result = malloc(sizeof(struct Vector3));
    struct Vector3* q1 = malloc(sizeof(struct Vector3));
    struct Vector3* q2 = malloc(sizeof(struct Vector3));
    result->ringInfo = v1->ringInfo;
    q1->ringInfo = v1->ringInfo;
    q2->ringInfo = v1->ringInfo;
    q1 -> x = result->ringInfo->product(v1->y, v2->z);
    q1 -> y = result->ringInfo->product(v1->z, v2->x);
    q1 -> z = result->ringInfo->product(v1->x, v2->y);
    q2 -> x = result->ringInfo->product(v1->z, v2->y);
    q2 -> y = result->ringInfo->product(v1->x, v2->z);
    q2 -> z = result->ringInfo->product(v1->y, v2->x);
    result = Differencevect(q1, q2);
    free(q1);
    free(q2);
    return result;
}



struct Vector3* Negativevect(struct Vector3* v1) {
    struct Vector3* result = malloc(sizeof(struct Vector3));
    result->ringInfo = v1->ringInfo;
    result -> x = result->ringInfo->negative(v1->x);
    result -> y = result->ringInfo->negative(v1->y);
    result -> z = result->ringInfo->negative(v1->z);
    return result;
}

struct Vector3* Scalarproduct(struct Vector3* v1, struct Vector3* v2) {
    struct Vector3* result = malloc(sizeof(struct Vector3));
    struct Vector3* result1 = malloc(sizeof(struct Vector3));
    result->ringInfo = v1->ringInfo;
    result1->ringInfo = v1->ringInfo;
    result -> x = result->ringInfo->product(v1->x, v2->x);
    result -> y = result->ringInfo->product(v1->y, v2->y);
    result -> z = result->ringInfo->product(v1->z, v2->z);
    result1 -> x = result1->ringInfo->sum(result -> x, result -> y);
    result1 -> x = result1->ringInfo->sum(result1 -> x, result -> z);
    result1 -> y = result->ringInfo->product(v1->y, v2->y);
    result1 -> z = result->ringInfo->product(v1->z, v2->z);
    free(result);
    return result1;
}
