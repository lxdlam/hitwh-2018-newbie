#include "testlib.h"

int main(int argc, char **argv)
{
    registerValidation(argc, argv);

    int N = inf.readInt(1, 1024, "N");
    inf.readEoln();

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            inf.readInt(0, 10, "C");
            if (j != N - 1)
                inf.readSpace();
        }

        inf.readEoln();
    }

    inf.readEof();

    return 0;
}
