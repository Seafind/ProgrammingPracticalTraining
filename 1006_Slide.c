#include <stdio.h>
#include <math.h>

int main (){
    int a, b;
    while (scanf("%d %d", &a, &b)!= EOF){
        printf("%.3f\n", sqrt(a * a + b * b));
    }
    return 0;
}