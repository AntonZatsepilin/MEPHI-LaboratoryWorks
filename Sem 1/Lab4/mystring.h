#ifndef mystring_h
#define mystring_h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
char *deleteelem (const char *str);
char* mystrcat(char* a, const char *b);
void mymemcpy(char* a, const char* b, size_t len);
char* mystrdup(const char *str);
char *getmy();
int proverka(const char *str);
int proverka2(const char *str);
#endif
