#include "RingInfo.h"
#include "Doublevect.h"
struct RingInfo* Create(
                        size_t size,
                        void* (*sum)(void*, void*),
                        void* (*difference)(void*, void*),
                        void* zero,
                        void* (*negative)(void*),
                        void* (*product)(void*, void*),
                        void* one)
{
    struct RingInfo* ringInfo = malloc(sizeof(struct RingInfo));
    ringInfo->size = size;
    ringInfo->sum = sum;
    ringInfo->difference = difference;
    ringInfo->zero = zero;
    ringInfo->negative = negative;
    ringInfo->product = product;
    ringInfo->one = one;
    return ringInfo;
}


