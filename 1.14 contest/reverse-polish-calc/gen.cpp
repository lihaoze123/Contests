#include <bits/stdc++.h>
#include "testlib.h"

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int init = opt<int>("init");

    std::string expr;
    std::vector<int> stk;
    while (expr.size() < init) {
        if (stk.size() >= 2 && rnd.next(0, 1)) {
            int b = stk.back();
            stk.pop_back();
            int a = stk.back(); 
            stk.pop_back();
            
            char op;
            while (true) {
                op = "+-*/"[rnd.next(0, 3)];
                if (op != '/' || b != 0) {
                    break;
                }
            }
            expr += op;
            
            if (op == '+') stk.push_back(a + b);
            else if (op == '-') stk.push_back(a - b);
            else if (op == '*') stk.push_back(a * b);
            else stk.push_back(a / b);
        } else {
            int x = rnd.next(1, 9);
            expr += std::to_string(x);
            stk.push_back(x);
        }
    }
    
    while (stk.size() > 1) {
        int b = stk.back();
        stk.pop_back();
        int a = stk.back();
        stk.pop_back();
        
        char op;
        while (true) {
            op = "+-*/"[rnd.next(0, 3)];
            if (op != '/' || b != 0) {
                break;
            }
        }
        expr += op;
        
        if (op == '+') stk.push_back(a + b);
        else if (op == '-') stk.push_back(a - b);
        else if (op == '*') stk.push_back(a * b);
        else stk.push_back(a / b);
    }
    std::cout << expr.size() << '\n';
    std::cout << expr << '\n';
    return 0;
}