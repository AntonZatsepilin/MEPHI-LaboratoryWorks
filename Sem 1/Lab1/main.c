#include <stdio.h>
int fib(int n){
    int a, b, i, c;
    printf("%d %d", 1, 1);
    a = 1;
    b = 1;
    for(i = 2; i < n; i++){
        c = a;
        a = b;
        b = c + b;
        printf(" %d", b);
    }
    return 0;
}

    
    int main() {
        int n;
        if (scanf("%d", &n) == 1){
            if (n == 1){
                printf("%d", 1);
            }else if (n > 1) {
                fib(n);
            } else {
                printf("Not correct");
            }
        }  else {
            printf("Not correct");
        }
        return 0;
    }
        
