#include <stdio.h>
#include <string.h>

#define SIZE 100010

typedef unsigned long long ull;

ull dp[SIZE][2];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(dp, 0, sizeof dp);
        int k, d;
        scanf("%d%d", &k, &d);
        dp[1][0] = 1;
        for (int i = 2; i < SIZE; i++)
        {
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
            if (i == k)
                dp[i][1] = 1;
            else if (i > k)
                dp[i][1] = dp[i - k][0];
        }

        printf("%llu\n", dp[d][0] + dp[d][1]);
    }

    return 0;
}