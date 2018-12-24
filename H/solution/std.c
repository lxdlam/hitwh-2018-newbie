#include <stdio.h>

int main()
{
    int T;
    long long x;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld", &x);
        if (x < 20190001)
            printf("%lld\n", x + 2018);
        else
            printf("20192018\n");
    }
    
    return 0;
}