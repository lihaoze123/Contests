#include "testlib.h"

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1, 300'000, "n");
    inf.readSpace();
    int m = inf.readInt(1, 300'000, "m");
    inf.readEoln();
    inf.readInts(n, -1000'000'000, 1000'000'000, "a_i");
    inf.readEoln();

    inf.readEof();
}
