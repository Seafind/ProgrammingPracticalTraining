#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n;
    while (scanf("%d", &n)!= EOF) {
        int a[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                if (abs(a[i]) > abs(a[j])) {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
        printf("%d", a[0]);
        for (int i = 1; i < n; i++) {
            printf(" %d", a[i]);
        }
        printf("\n");
    }
    return 0;
}