#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    
    int n = inf.readInt(1, 100'000, "n");
    inf.readSpace();
    int m = inf.readInt(1, 100'000, "m");
    inf.readEoln();
    
    std::string s = inf.readToken("[a-zA-Z0-9]{" + std::to_string(n) + "}", "s");
    inf.readEoln();
    
    for (int i = 0; i < m; i++) {
        int l1 = inf.readInt(1, n, "l1");
        inf.readSpace();
        int r1 = inf.readInt(1, n, "r1");
        inf.readSpace();
        int l2 = inf.readInt(1, n, "l2");
        inf.readSpace();
        int r2 = inf.readInt(1, n, "r2");
        inf.readEoln();
        
        ensuref(l1 <= r1, "l1 should not be greater than r1");
        ensuref(l2 <= r2, "l2 should not be greater than r2");
    }
    
    inf.readEof();
    return 0;
}
