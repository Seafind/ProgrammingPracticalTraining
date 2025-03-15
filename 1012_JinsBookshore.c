#include <stdio.h>

int main() {
    int n;
    scanf ("%d", &n);
    int year[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &year[i]);
    }
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (year[i] > year[j]) {
                int temp = year[i];
                year[i] = year[j];
                year[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d\n", year[i]);
    }
    return 0;
}
