#include "testlib.h"

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 100'000, "n");
    inf.readEoln();
    inf.readInts(n, 1, 1000'000'000, "a_i");
    inf.readEoln();
    inf.readEof();
}