#include <stdio.h>
#include <math.h>

int main()
{
    long long n;
    scanf("%lld", &n);

    long long result = (long long)ceil(sqrt(n));
    printf("%lld\n", result);
    
    return 0;
}