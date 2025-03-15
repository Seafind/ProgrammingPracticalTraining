#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    qsort (arr, N, sizeof(int), compare);
    int K;
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        int x;
        scanf("%d", &x);
        printf ("%d\n", arr[x-1]);
    }
    return 0;
}
