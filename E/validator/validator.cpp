#include "testlib.h"

int main(int argc, char **argv)
{
    registerValidation(argc, argv);

    int T = inf.readInt(1, 233, "T");
    inf.readEoln();

    for (int i = 0; i < T; i++)
    {
        int N = inf.readInt(0, 233, "N");
        inf.readEoln();

        for (int i = 0; i < N; i++)
        {
            inf.readInt(-233, 233, "P");
            inf.readSpace();
        }
        
        int PN = inf.readInt(-233, 233, "PN");
        ensure(PN != 0);

        inf.readEoln();
    }

    inf.readEof();

    return 0;
}
