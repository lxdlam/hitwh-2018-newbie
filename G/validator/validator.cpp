#include "testlib.h"

const int bound = 2.33e8;

int main(int argc, char **argv)
{
    registerValidation(argc, argv);

    int T = inf.readInt(1, 23333, "T");
    inf.readEoln();

    for (int i = 0; i < T; i++)
    {
        inf.readInt(0, bound, "N");
        inf.readEoln();
    }

    inf.readEof();

    return 0;
}