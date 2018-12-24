#include "testlib.h"

const long long bound = 2.33e18;

int main(int argc, char **argv)
{
    registerValidation(argc, argv);

    int T = inf.readInt(1, 23333, "T");
    inf.readEoln();

    for (int i = 0; i < T; i++)
    {
        inf.readLong(1, bound, "K");
        inf.readEoln();
    }

    inf.readEof();

    return 0;
}