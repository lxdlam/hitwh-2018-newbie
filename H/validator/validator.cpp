#include "testlib.h"

const int long long bound = 1e18;

int main(int argc, char **argv)
{
    registerValidation(argc, argv);

    int T = inf.readInt(1, 10, "T");
    inf.readEoln();

    for (int i = 0; i < T; i++)
    {
        inf.readLong(1, bound, "x");
        inf.readEoln();
    }

    inf.readEof();

    return 0;
}