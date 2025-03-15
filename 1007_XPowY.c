#include <stdio.h>
#include <math.h>

int main (){
    double x, y;
    while (scanf("%lf %lf", &x, &y)!= EOF){
        printf("%.3lf\n", pow(x, y));
    }
    return 0;
}