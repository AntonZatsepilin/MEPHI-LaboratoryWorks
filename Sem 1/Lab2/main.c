#include <stdio.h>
#include<math.h>
double ln(double x, int n){
    double z, r, q;
        q = 0;
        z = x;
        r = z;
    int i = 1;
    int k = 0;
    while(fabs(r - q) >= pow(10.0, -n)){
        k++;
        z *= (-1) * (2 * i - 1) * powl(x, (2 * i) + 1) / ((2 * i) * (2 * i + 1));
        q = r;
        r += z;
        i++;
    }
    printf("%d   ", k);
        return(r);
    }
int main() {
    double x; 
    int n;
    char c;
    while (scanf("%lf%c", &x, &c) != 2){
        if (c == -1){
            printf("Not correct");
        }else{
            printf("Not correct. Try again:");
            
            while(getchar() != '\n');
        }
        
    }
    char c1;
    while (scanf("%d%c", &n, &c1) != 2){
        if (c1 == -1){
            printf("Not correct");
        }else{
            printf("Not correct. Try again:");
            
            while(getchar() != '\n');
        }
        
    }
        printf("%.15lf", ln(x, n));
    return 0;
}
