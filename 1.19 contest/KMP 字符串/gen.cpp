#include <bits/stdc++.h>
#include "testlib.h"

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    int n = opt<int>("n");
    int m = opt<int>("m");
    int type = opt<int>("type");
    
    std::string charset;
    if (type == 1) {
        charset = "ab";
    } else if (type == 2) {
        charset = "abcdefghijklmnopqrstuvwxyz";
    } else {
        charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    }
    
    std::string p;
    for (int i = 0; i < n; i++) {
        p += rnd.any(charset);
    }
    
    std::string s;
    int remaining = m;
    while (remaining > 0) {
        if (remaining >= n && rnd.next(0, 2) > 0) {
            s += p;
            remaining -= n;
        } else {
            s += rnd.any(charset);
            remaining--;
        }
    }
    
    println(n);
    println(p);
    println(m);
    println(s);
} 