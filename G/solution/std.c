#include <stdio.h>

int main()
{
    int T, n;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        if (n & 1)
            printf("0 %d %d %d\n", n, n, 1);
        else
            printf("0 %d 0 %d\n", n, n);
    }
}