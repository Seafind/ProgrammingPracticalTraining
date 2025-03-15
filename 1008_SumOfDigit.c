#include <stdio.h>

int main (){
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        int result = 0;
        long long a, b, sum = 0;
        scanf("%lld %lld", &a, &b);
        sum = a + b;
        while (sum > 0){
            sum = sum / 10;
            result++;
        }
        printf("%d\n", result);
    }
    return 0;
}