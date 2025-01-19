#include "testlib.h"

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1, 100'000, "n");
    inf.readEoln();

    for (int i = 0; i < n; i ++) {
        inf.readInts(6, 0, 10'000'000 - 1, "a");
        inf.readEoln();
    }

    inf.readEof();
}