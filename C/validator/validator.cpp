#include "testlib.h"

const int bound = 1e9;

int main(int argc, char **argv)
{
    registerValidation(argc, argv);

    int T = inf.readInt(1, 100, "T");
    inf.readEoln();

    for (int i = 0; i < T; i++)
    {
        inf.readInt(-bound, bound, "n");
        inf.readSpace();
        inf.readInt(-bound, bound, "m");
        inf.readEoln();
    }

    inf.readEof();

    return 0;
}