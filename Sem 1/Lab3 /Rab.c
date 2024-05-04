#include "Rab.h"

int inputint(){
    char c;
    int x;
    while(scanf("%u", &x) != 1 || (c = getchar()) != '\n'){
        if(c == -1){
            printf("Incorrect. Exit program.");
            exit(1);
        } else {
            printf("Incorrect. Try again:");
        }
            while(getchar() != '\n');
        }
        return x;
    }

int *array_input(int *len, int *size){
    printf("Number of elements:");
    *len = inputint();
    *size = *len * 2;
    int *data = malloc(*size * sizeof(int));
    if(!data){
        printf("Filed to memory\n");
        return NULL;
    }
    for (int i = 0; i < *len; i++){
     scanf("%d", &data[i]);
    }
    return data;
}

void vstavka(int **dataPtr, int *len, int *size) {
    int *data = *dataPtr;
    int *p = data;
    int z,e;
    printf("Введите индекс: ");
    z = inputint();
    printf("Введите элемент: ");
    e = inputint();
    if(*size == *len + 1){
        data = realloc(data, *size * sizeof(int) * 2);
        *size = *size * 2;
    }
    if (data == NULL) {
        printf("Allocation error");
        exit(-1);
    }
    if(z <= *len){
        for(int i = *len; i >= z; i--){
            data[i+1] = data[i];
        }
        *len += 1;
        data[z] = e;
    } else {
        *len += 1;
        data[*len - 1] = e;
    }
    *dataPtr = data;
}

void deleteindex(int **dataPtr, int *len, int *size) {
    int z;
    int *data = *dataPtr;
    printf("Введите индекс: ");
    z = inputint();
    if(*size / 2 > *len - 1){
        data = realloc(data, (*size * sizeof(int)) / 2);
        *size = *size / 2;
    }
    for(int i = z; i <= *len; i++){
        data[i] = data[i + 1];
    }
    *len -= 1;
    *dataPtr = data;
}

int proverka(int x){
    if(x>9){
        while(x > 9){
            if((x % 10) >= ((x / 10) % 10)){
                return 1;
            } else {
                x = x / 10;
            }
        }
        return 0;
    } else {
        return 1;
    }
}

void obrabotka(int *data, int *len) {
    for(int i = 0; i < *len; i++){
        if(proverka(data[i]) == 0){
            for(int j = i + 1; j < *len; j++){
                data[j - 1] = data[j];
            }
            *len -= 1;
            i--;
        }
    }
}

void vivod(int *data, int *len) {
    for(int i = 0; i < *len; i++){
        printf("%d ", data[i]);
    }
}
