#ifndef Rab_h
#define Rab_h
#include <stdio.h>
#include<stdlib.h>
int *array_input(int *len, int *size);
void vstavka(int **dataPtr, int *len, int *size);
int proverka(int x);
void obrabotka(int *data, int *len);
void vivod(int *data, int *len);
void deleteindex(int **dataPtr, int *len, int *size);
int inputint();
#endif /* Rab_h */
