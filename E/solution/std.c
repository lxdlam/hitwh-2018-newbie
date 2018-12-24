#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, a;
        scanf("%d", &n);
        if (n & 1)
            printf("1\n0.0\n");
        else
            printf("0\n");
        while (n--)
            scanf("%d", &a);
        scanf("%d", &a);
    }

    return 0;
}