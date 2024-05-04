#include "Rab.h"
int main() {
    int len;
    int size;
    int k = 0;
    int *data = array_input(&len, &size);
    while(k != 5){
        printf("\n1. Вставка нового элемента в массив по индексу.\n2. Удаление элемента массива по индексу.\n3. Обработка данных.\n4. Вывод текущего состояния массива.\n5. Выйти из программы.\n");
        k = inputint();
        if(k == 1){
            int** dataPtr = &data;
            vstavka(dataPtr, &len, &size);
            data = *dataPtr;
        }
        if(k == 2){
            int** dataPtr = &data;
            deleteindex(dataPtr, &len, &size);
            data = *dataPtr;
        }
        if(k == 3){
            obrabotka(data, &len);
        }
        if(k == 4){
            vivod(data, &len);
        }
        if(k == 5){
            k = 5;
        }
    }
    if(data != NULL){
    free(data);
    data = NULL;
    }
  return 0;
}
