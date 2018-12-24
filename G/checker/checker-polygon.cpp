#include "testlib.h"

using namespace std;

const int MAX = 1000000000;

long long calc(int a, int b, int c, int d)
{
    return min(abs(a - b), abs(c - d)) ^ a ^ b ^ c ^ d;
}

int main(int argc, char **argv)
{
    registerTestlibCmd(argc, argv);

    int T = inf.readInt();

    for (int i = 0; i < T; i++)
    {
        int n = inf.readInt();

        int a = ouf.readInt(0, MAX);
        ouf.readSpace();
        int b = ouf.readInt(0, MAX);
        ouf.readSpace();
        int c = ouf.readInt(0, MAX);
        ouf.readSpace();
        int d = ouf.readInt(0, MAX);
        ouf.readEoln();

        long long conVal = calc(a, b, c, d);

        if (n != conVal)
            quitf(_wa, "The value contestant has given is %d, not %d.", conVal, n);
    }

    ouf.readEof();

    quitf(_ok, "All of the contestants' choice are acceptable.");
}