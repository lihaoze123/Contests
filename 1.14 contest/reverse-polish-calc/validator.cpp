#include <bits/stdc++.h>
#include "testlib.h"

bool isValid(const std::string &expr) {
    std::vector<int> stk;
    for (char c : expr) {
        if (isdigit(c)) {
            stk.push_back(c - '0');
        } else {
            if (stk.size() < 2) {
                return false;
            }
            stk.pop_back();
            stk.pop_back();
            stk.push_back(1);
        }
    }
    return stk.size() == 1;
}

bool hasZeroDivision(const std::string &expr) {
    std::vector<int> stk;
    for (char c : expr) {
        if (isdigit(c)) {
            stk.push_back(c - '0');
        } else {
            int b = stk.back();
            stk.pop_back();
            int a = stk.back();
            stk.pop_back();
            
            if (c == '/') {
                if (b == 0) {
                    return true;
                }
                stk.push_back(a / b);
            } else if (c == '+') {
                stk.push_back(a + b);
            } else if (c == '-') {
                stk.push_back(a - b);
            } else {
                stk.push_back(a * b);
            }
        }
    }
    return false;
}


int main(int argc, char *argv[]) {
    registerValidation(argc, argv);

    const std::string valid_chars = "0123456789+-*/";

    int n = inf.readInt(1, 100'000, "n");
    inf.readEoln();

    std::string expr;
    for (int i = 0; i < n; i++) {
        char c = inf.readChar();
        ensuref(std::set(valid_chars.begin(), valid_chars.end()).count(c), "Invalid character in expression.");
        expr += c;
    }
    inf.readEoln();

    ensuref(isValid(expr), "The expression is not a valid postfix expression.");
    ensuref(hasZeroDivision(expr) == false, "The expression has zero division.");

    inf.readEof();
}
