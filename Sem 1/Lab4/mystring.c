#include "mystring.h"

size_t mystrlen(const char *s){
    int res = 0;
    while (*s) {
        ++s;
        ++res;
    }
    return res;
}

char* mystrcat(char* a, const char *b){
    char *ptr = a + mystrlen(a);
    while (*b != '\0'){
        *ptr++ = *b++;
    }
    *ptr = '\0';
    return a;
}

void mymemcpy(char* a, const char* b, size_t len) {
    for (size_t i = 0; i < len; ++i){
        a[i] = b[i];
    }
}


char* mystrdup(const char* str) {
    char* a = calloc(mystrlen(str) + 1, sizeof(char));
    mymemcpy(a, str, mystrlen(str) + 1);
    return a;
}



char *getmy(){
    char *ptr = (char *)malloc(1);
    char buf[81];
    int n, len = 0;
    *ptr = '\0';
    do{
        n = scanf("%80[^\n]", buf);
        if(n < 0){
            
            free(ptr);
            ptr = NULL;
            continue;
            
        }
        if(n == 0)
            
            scanf("%*c");
        
        else {
            
            len += mystrlen(buf);
            ptr = (char *) realloc(ptr, len + 1);
            mystrcat(ptr, buf);
            
        }
    }
    while(n > 0);
    return ptr;
}

int proverka(const char *str){
    int k = 0;
    for (int i=1; str[i]!=0; i++){
        if(str[i] == '.' || str[i] == ';'){
            k = 1;
        }
    }
    return k;
}

int proverka2(const char *str){
    int a = 0, b = 0, k = 0;
    for (int i=1; str[i]!=0; i++){
        if(str[i] == '.'){
            a = i;
            break;
        }
    }
    
    for (int i=1; str[i]!=0; i++){
        if(str[i] == ';'){
            b = i;
        }
    }
    if (a < b){
        k = 1;
    }
    return k;
}




char *deleteelem (const char *str){
    
    clock_t clock1 = clock();
    
    char *s = mystrdup(str);
    for (int i=1; s[i]!=0; i++) {
           if (s[i]=='\t'){
               s[i] = ' ';
           }
           }
    
    
    int j = 1;
    for (int i=1; s[i]!=0; i++) {
        if((s[i] == ' ') && (s[i-1]==' '))
            continue;
    s[j++] = s[i];
    }
    if (s[j-1]==' ') j--;
    s[j] = 0;
    
   
    
    
    size_t x = 0, y = mystrlen(str);
    for (int i=1; str[i]!=0; i++) {
        if(s[i] == '.'){
            x = i;
            break;
        }
    }
    for (int i=1; str[i]!=0; i++) {
        if(s[i] == ';'){
            y = i;
        }
    }
    if (x < y){
        char *res = malloc((y - x) * sizeof(char));
        for(unsigned i = 0; i < y - x + 1; i++){
            res[i] = s[x + i];
        }
        res[y + 1] = '\0';
        free(s);
        clock_t clock2 = clock();
        double t = difftime(clock2, clock1);
        printf("Время: %f\n", t/CLOCKS_PER_SEC);
        return res;
    } else {
        clock_t clock2 = clock();
        double t = difftime(clock2, clock1);
        printf("Время: %f\n", t/CLOCKS_PER_SEC);
        return s;
    }
}

