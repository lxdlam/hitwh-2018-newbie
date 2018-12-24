#include "testlib.h"

int main(int argc, char **argv)
{
    registerValidation(argc, argv);

    int T = inf.readInt(1, 233, "T");
    inf.readEoln();

    for (int i = 0; i < T; i++)
    {
        inf.readInt(2, 100000, "K");
        inf.readSpace();
        inf.readInt(1, 100000, "D");
        inf.readEoln();
    }

    inf.readEof();

    return 0;
}
