#include "testlib.h"

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int n;
    
    while (true) {
        n = inf.readInt(0, 100'000, "n");
        if (n == 0) {
            break;
        }
        inf.readSpace();
        inf.readInts(n, 0, 1000'000'000, "h");
        inf.readEoln();
    }
    inf.readEof();
}
