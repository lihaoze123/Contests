#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    
    int n = inf.readInt(2, 100'000, "n");
    inf.readEoln();
    
    inf.readInts(n, 0, (1 << 31) - 1, "a");
    inf.readEoln();
    
    inf.readEof();
    return 0;
}
