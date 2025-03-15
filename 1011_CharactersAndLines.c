#include <stdio.h>

int main() {
    char ch;
    int row = 0;
    int sum = 0;
    int result[1000]= {0};
    int i = 0;
    while ((ch = getchar()) != EOF) {
        if (ch == '\n') {
            row++;
            i++;
        }
        else {
            sum++;
            result[i]++;
        }
    }
    int max = 0;
    for (i = 0; i < row; i++) {
        if (result[i] > max) {
            max = result[i];
        }
    }
    printf("%d,%d,%d\n", sum, row, max);
    return 0;
}