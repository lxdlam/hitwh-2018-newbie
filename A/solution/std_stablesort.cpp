#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

struct Node
{
    double ptt;
    int pos;
};

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
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<Node> v;
        int s;
        double p;
        for (int i = 0; i < n; i++)
        {
            cin >> s >> p;
            v.push_back({getPtt(s, p), i});
        }

        stable_sort(v.begin(), v.end(), [](const Node &a, const Node &b) { return a.ptt > b.ptt; });

        double sum = 0;

        for (int i = 0; i < 30; i++)
        {
            sum += v[i].ptt;
            v[i].ptt = -1;
        }

        stable_sort(v.begin(), v.end(), [](const Node &a, const Node &b) { return a.pos < b.pos; });

        int cnt = 0;

        for (int i = 0; cnt < 10; i++)
        {
            if (v[i].ptt != -1)
            {
                sum += v[i].ptt;
                cnt++;
            }
        }

        cout << fixed << setprecision(2) << sum / 40 << '\n';
    }
}