#include <stdio.h>
#include <string.h>
#include <assert.h>

#define SIZE 1010

struct Node
{
    double ptt;
    int pos;
} node[SIZE];

void sortByPtt(int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (node[j].ptt < node[j + 1].ptt)
            {
                double tPtt = node[j].ptt;
                node[j].ptt = node[j + 1].ptt;
                node[j + 1].ptt = tPtt;

                int tPos = node[j].pos;
                node[j].pos = node[j + 1].pos;
                node[j + 1].pos = tPos;
            }
        }
    }
}

void sortByPos(int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (node[j].pos > node[j + 1].pos)
            {
                double tPtt = node[j].ptt;
                node[j].ptt = node[j + 1].ptt;
                node[j + 1].ptt = tPtt;

                int tPos = node[j].pos;
                node[j].pos = node[j + 1].pos;
                node[j + 1].pos = tPos;
            }
        }
    }
}

double getPtt(int s, double p)
{
    if (s >= 10000000)
        return p + 2;
    else if (s >= 9950000)
        return p + 1.5 + 1.0 * (s - 9950000) / 100000;
    else if (s >= 9800000)
        return p + 1 + 1.0 * (s - 9800000) / 400000;
    else
    {
        double ret = p + 1.0 * (s - 9500000) / 300000;
        if (ret < 0)
            return 0.0;
        else
            return ret;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(node, 0, sizeof node);
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            int s;
            double p;
            scanf("%d %lf", &s, &p);
            node[i].ptt = getPtt(s, p);
            node[i].pos = i;
        }

        double total = 0.0;

        sortByPtt(n);

        for (int i = 0; i < 30; i++)
        {
            total += node[i].ptt;
            node[i].ptt = -1;
        }

        sortByPos(n);
        int count = 0;
        for (int i = 0; i < n && count < 10; i++)
        {
            if (node[i].ptt >= 0)
            {
                count++;
                total += node[i].ptt;
            }
        }

        printf("%0.2f\n", total / 40.0);
    }

    return 0;
}