#include <stdio.h>
#include <math.h>

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int n;
        scanf("%d", &n);
        long long ans = (long long)pow(2, n);
        printf("case #%d:\n", i);
        printf("%lld\n", ans);
    }
    return 0;
}
