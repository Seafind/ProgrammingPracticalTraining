#include <stdio.h>

int main (){
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++){
        int a, n;
        scanf("%d %d", &a, &n);
        if (n == 0){
            printf("case #%d:\n1\n", i);
            continue;
        }
        unsigned long long result = 1;
        for (int j = 0; j < n; j++){
            result *= a;
        }
        printf("case #%d:\n%llu\n", i, result);
    }
    return 0;
}