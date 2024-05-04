#include "mystring.h"
#define PROMPT "> "
int main(){
    char *str = getmy(PROMPT);
    while (str != NULL){
    char *output = deleteelem(str);
    printf("\"%s\"\n", output);
free(str);
free(output);
str = getmy(PROMPT);

}

return 0;
}

