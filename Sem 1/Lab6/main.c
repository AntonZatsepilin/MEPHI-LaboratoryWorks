#include <stdio.h>
#include "list.h"

int main () {
    int m, n;
    while(1) {
        list *list = list_new();
        if(NULL == list){
            return 0;
        }

        printf("Введите строку:");
        
        char c;
        
        while((c = (char)getchar()) != '\n') {
            
            if (c == EOF){
                list_delete(list);
                return 0;
            }
            if(list_push_back(list, c) == 1) {
                list_delete(list);
                printf("Ошибка!!!\n");
                return 1;
            }
        }
       printf("Удаление:");
       scanf("\n%d", &n);
        c = (char)getchar();
        list_print(list);

        list_remove_dups(list);
        list_remove_spaces(list);
        list_process(list, n);
        list_remove_dups(list);
    
        printf("\"");
        list_print(list);
        printf("\n");

        list_delete(list);
    }
}
