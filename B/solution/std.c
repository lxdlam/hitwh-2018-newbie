#include <stdio.h>

#define SIZE 66

typedef long long ll;

ll ts[SIZE];

void init()
{
    ts[0] = 0;

    for (int i = 1; i < SIZE; i++)
        ts[i] = ts[i - 1] * 2LL + 1LL;
}

int dfs(ll pos, ll size, int status)
{
    if (pos == (size + 1) / 2)
        return status;
    else if (pos > (size + 1) / 2)
        return dfs(pos - (size + 1) / 2, size / 2, 1);
    else
        return dfs(pos, size / 2, 0);
}

int main()
{
    init();
    int T, ret;
    ll n;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld", &n);
        for (int i = 1; i < SIZE; i++)
        {
            if (n < ts[i])
            {
                ret = dfs(n, ts[i], 0);
                break;
            }
        }

        if (ret)
            printf("Cruisers\n");
        else
            printf("Destroyer\n");
    }
}