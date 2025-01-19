#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    
    int n = inf.readInt(1, 100'000, "n");
    inf.readEoln();
    
    std::string p = inf.readToken("[a-zA-Z0-9]+", "p");
    ensuref(p.length() == n, "Length of P must be equal to n");
    inf.readEoln();
    
    int m = inf.readInt(1, 1'000'000, "m");
    inf.readEoln();
    
    std::string s = inf.readToken("[a-zA-Z0-9]+", "s");
    ensuref(s.length() == m, "Length of S must be equal to m");
    inf.readEoln();
    
    inf.readEof();
} 