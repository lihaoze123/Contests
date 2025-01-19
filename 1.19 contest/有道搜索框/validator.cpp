#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    
    int n = inf.readInt(1, 10000, "n");
    inf.readEoln();
    
    for (int i = 0; i < n; i++) {
        std::string word = inf.readToken("[a-z]{1,20}", "word");
        inf.readEoln();
    }
    
    int q = inf.readInt(1, 10000, "q");
    inf.readEoln();
    
    for (int i = 0; i < q; i++) {
        std::string query = inf.readToken("[a-z]{1,20}", "query");
        inf.readEoln();
    }
    
    inf.readEof();
} 