#include <stdio.h>

typedef struct keyboard {
    int price;
    char type[10];
} keyboard;

int main (){
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        int m;
        scanf("%d", &m);
        keyboard keyboards[m];
        for (int j = 0; j < m; j++) {
            scanf("%d %s", &keyboards[j].price, keyboards[j].type);
        }
        for (int j = 0; j < m-1; j++) {
            for (int k = j + 1; k < m; k++) {
                if (keyboards[j].price > keyboards[k].price) {
                    keyboard temp = keyboards[j];
                    keyboards[j] = keyboards[k];
                    keyboards[k] = temp;
                }
            }
        }
        int countU = 0, countP = 0;
        int count = 0;
        int sum = 0;
        for (int j = 0; j < m; j++)
        {
            if (keyboards[j].type[0] == 'U' && countU < a)
            {
                sum += keyboards[j].price;
                count++;
                countU++;
            }
            else if (keyboards[j].type[0] == 'P' && countP < b)
            {
                sum += keyboards[j].price;
                count++;
                countP++;
            }
            else if (c>0)
            {
                sum += keyboards[j].price;
                count++;
                c--;
            }
        }
        printf("case #%d:\n", i);
        printf("%d %d\n", count, sum);
    }
    return 0;
}