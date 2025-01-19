#include <bits/stdc++.h>
#include "testlib.h"

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    int n = opt<int>("n");
    int type = opt<int>("type");
    
    println(n);
    
    if (type == 1) {
        for (int i = 0; i < n; i++) {
            if (i > 0) std::cout << " ";
            std::cout << rnd.next(0, 1'000'000'000);
        }
    } 
    else if (type == 2) {
        for (int i = 0; i < n; i++) {
            if (i > 0) std::cout << " ";
            std::cout << (i % 2 == 0 ? 1'000'000'000 : 0);
        }
    }
    else if (type == 3) {
        for (int i = 0; i < n; i++) {
            if (i > 0) std::cout << " ";
            int val = (1 << rnd.next(0, 29));
            std::cout << val;
        }
    }
    else if (type == 4) {
        for (int i = 0; i < n; i++) {
            if (i > 0) std::cout << " ";
            std::cout << rnd.next(0, 1023);
        }
    }
    std::cout << "\n";
    
    return 0;
} 