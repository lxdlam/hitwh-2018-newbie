#include "testlib.h"
#include <set>

const long long factor = 100000000;

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

int main(int argc, char **argv)
{
    registerValidation(argc, argv);

    int T = inf.readInt(1, 100, "T");
    inf.readEoln();

    std::set<long long> se;

    for (int i = 0; i < T; i++)
    {
        int n = inf.readInt(40, 1000, "n");
        inf.readEoln();

        // use to check for some critical issue
        // thx to Gao
        se.clear();

        for (int j = 0; j < n; j++)
        {
            int s = inf.readInt(0, 10000000, "s");
            inf.readSpace();
            double p = inf.readDouble(1.0, 12.0, "p");
            inf.readEoln();

            long long ptt = getPtt(s, p) * factor; // we accept 10-8 error

            ensuref(!se.count(ptt), "Same ptt under the 10-8 error [testcase %d]", i + 1);
            se.insert(ptt);
        }
    }

    inf.readEof();

    return 0;
}