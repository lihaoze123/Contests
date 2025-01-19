#include <bits/stdc++.h>
#include "testlib.h"

std::string gen_string(int length) {
    std::string result;
    std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (int i = 0; i < length; i++) {
        result += charset[rnd.next(0, (int)charset.length() - 1)];
    }
    return result;
}

std::pair<int, int> gen_query(int n) {
    int l = rnd.next(1, n);
    int r = rnd.next(l, n);
    return {l, r};
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    int n = opt<int>("n");
    int m = opt<int>("m");
    
    std::string mode = opt<std::string>("mode");
    
    println(n, m);
    
    if (mode == "same_substrings") {
        std::string base = gen_string(n / 3);
        std::string s;
        while (s.length() < n) {
            s += base;
        }
        s = s.substr(0, n);
        println(s);
        
        for (int i = 0; i < m; i++) {
            if (rnd.next(0, 1) == 0) {
                int len = rnd.next(1, std::min(20, n));
                int start1 = rnd.next(1, n - len + 1);
                int start2 = rnd.next(1, n - len + 1);
                println(start1, start1 + len - 1, start2, start2 + len - 1);
            } else {
                auto q1 = gen_query(n);
                auto q2 = gen_query(n);
                println(q1.first, q1.second, q2.first, q2.second);
            }
        }
    } else if (mode == "all_same") {
        char c = rnd.next('a', 'z');
        std::string s(n, c);
        println(s);
        
        for (int i = 0; i < m; i++) {
            auto q1 = gen_query(n);
            auto q2 = gen_query(n);
            println(q1.first, q1.second, q2.first, q2.second);
        }
    } else if (mode == "all_different") {
        std::string s;
        std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        for (int i = 0; i < n; i++) {
            if (i < charset.length()) {
                s += charset[i];
            } else {
                s += charset[rnd.next(0, (int)charset.length() - 1)];
            }
        }
        println(s);
        
        for (int i = 0; i < m; i++) {
            auto q1 = gen_query(n);
            auto q2 = gen_query(n);
            println(q1.first, q1.second, q2.first, q2.second);
        }
    } else {
        println(gen_string(n));
        
        for (int i = 0; i < m; i++) {
            auto q1 = gen_query(n);
            auto q2 = gen_query(n);
            println(q1.first, q1.second, q2.first, q2.second);
        }
    }
    
    return 0;
} 