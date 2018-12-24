#include <stdio.h>

long long func(long long x)
{
    if (x < 20190001)
        return x + 2018;
    else
        return func(func(x - 2019));
}

int main()
{
    int T;
    long long x;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld", &x);
        printf("%lld\n", func(x));
    }
    return 0;
}