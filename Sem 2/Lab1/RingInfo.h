#ifndef RingInfo_h
#define RingInfo_h

#include <stdio.h>
#include <stdlib.h>
struct RingInfo{
    size_t size;
    void* (*sum)(void*, void*);
    void* (*difference)(void*, void*);
    void* zero;
    void* (*negative)(void*);
    void* (*product)(void*, void*);
    void* one;
};
struct RingInfo* Create(
                        size_t size,
                        void* (*sum)(void*, void*),
                        void* (*differenc)(void*, void*),
                        void* zero,
                        void* (*negative)(void*),
                        void* (*product)(void*, void*),
                        void* one);

#endif /* RingInfo_h */
