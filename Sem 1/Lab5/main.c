#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "point.h"
#define PROMPT " \t"
#include<time.h>

int main() {
    
    int ln;
    int c;
    int kol;
       FILE *fptr;
       if ((fptr = fopen("/Users/anton/Desktop/Программы С/Lab5 все файлы/Lab5_2/Lab5_2/data.txt","r")) == NULL){
           printf("Error! opening file ");
           return 1;
       }
    
    FILE *pt;
    if ((pt = fopen("/Users/anton/Desktop/Программы С/Lab5 все файлы/Lab5_2/Lab5_2/out.txt","w")) == NULL){
        printf("Error! opening file ");
        return 1;
    }
    
    
    
    fscanf(fptr,"%d", &ln);
    fscanf(fptr,"%d", &kol );
    fscanf(fptr, "%d", &c);
    
    Point cars[ln];
    int m = 0;
    double time = 0;
    for (int j = 0; j < kol; j ++){
        for(int i = 0; i < ln; i++){
            
            
            m = rand()%1000;
            cars[i].r = m;
        }
        
        
        if (c == 1){
            double start = clock();
            comb_sort(cars, ln);
            time += (clock() - start) / CLOCKS_PER_SEC;
        } else if(c == 2){
            double start = clock();
            sortvib(cars, ln);
            time += (clock() - start) / CLOCKS_PER_SEC;
        } else if(c == 3){
            double start = clock();
            sortvib(cars, ln);
            time += (clock() - start) / CLOCKS_PER_SEC;
            qsort(cars, ln, sizeof(Point),
                  (int (*)(const void *, const void *)) point_cmp_3);
        }
        
    }
    fprintf(pt, "Time is: %.41lf\n", time/kol);
    fclose(fptr);
    fclose(pt);
       return 0;
}
