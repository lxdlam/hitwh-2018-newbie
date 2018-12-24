#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        if (a < 0 && b < 0)
            printf("%lld\n", -a * b);
        else
            printf("%lld\n", a * b);
    }

    return 0;
}