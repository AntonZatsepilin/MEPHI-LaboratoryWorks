#include <stdio.h>
#include "point.h"
#include <stdlib.h>
#include <string.h>
#define F (1.24733)

Point point_new(char mark[17], char name[21], int r) {
    Point p = {*mark, *name, r};
    return p;
}

void point_print (const Point *p, FILE* pt) {
    fprintf (pt, "{%s, %s, %d}", p->mark,p->name, p->r) ;
    
}

void point_array_print(const Point *arr, int len, FILE* pt){
    for (int i = 0; i < len; ++i) {
        fprintf (pt, "a[%d] = ", i);
        point_print(arr + i, pt);
        fprintf (pt, "\n") ;
    }
}

char *getmy(FILE *fptr){
    char *ptr = (char *)malloc(1);
    char buf[81];
    int n, len = 0;
    *ptr = '\0';
    do{
        n = fscanf(fptr, "%80[^\n]", buf);
        if(n < 0){
            
            free(ptr);
            ptr = NULL;
            continue;
            
        }
        if(n == 0)
            
            fscanf(fptr, "%*c");
        
        else {
            
            len += strlen(buf);
            ptr = (char *) realloc(ptr, len + 1);
            strcat(ptr, buf);
            
        }
    }
    while(n > 0);
    return ptr;
}

int point_cmp_1(const Point *p1, const Point *p2) {
    return strcmp(p1->mark, p2->mark);
}

int point_cmp_2(const Point *p1, const Point *p2) {
    return strcmp(p1->name, p2->name);
}

int point_cmp_3(const Point *p1, const Point *p2) {
    return p1->r - p2->r;
}

int point_cmp_1r(const Point *p1, const Point *p2) {
    return strcmp(p2->mark, p1->mark);
}

int point_cmp_2r(const Point *p1, const Point *p2) {
    return strcmp(p2->name, p1->name);
}

int point_cmp_3r(const Point *p1, const Point *p2) {
    return p2->r - p1->r;
}

void comb_sort(Point *cars, int len) {
    int g = len;
    int swaps = 1;
    int i, j;
    while ( g > 1 || swaps ) {
        g = (int)(g / F);
        if ( g < 1 ){
            g = 1;
        }
            swaps = 0;
            for ( i = 0; i < len - g; ++i ) {
                j = i + g;
                if ( cars[i].r > cars[j].r ) {
                    int t = cars[i].r;
                    cars[i].r = cars[j].r;
                    cars[j].r = t;
                    swaps = 1;
                }
            }
        }
    }

void sortvib(Point *cars, int len){
    int tmp, mp;
    
    for (int i = 0; i < len; i++)
    {
        mp = i;
        for (int j = i + 1; j < len; j++)
            if (cars[mp].r > cars[j].r){
                mp = j;
            }
        tmp = cars[mp].r;
        cars[mp].r = cars[i].r;
        cars[i].r = tmp;
    }
}


