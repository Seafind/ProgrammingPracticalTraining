#include <stdio.h>

int main (){
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++){
        int M, K;
        scanf("%d %d", &M, &K);
        int arr[M];
        for (int j = 0; j < M; j++){
            scanf(" %d", &arr[j]);
        }
        int sum = 0;
        for (int j = 0; j < K; j++){
            sum += arr[j];
        }
        printf("%d\n", sum);
    }
    return 0;
}