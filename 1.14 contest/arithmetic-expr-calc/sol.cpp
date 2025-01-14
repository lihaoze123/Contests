#include <bits/stdc++.h>

using i64 = long long;

i64 qpow(i64 a, i64 b) {
    i64 res = 1;
    for (; b; b >>= 1) {
        if (b & 1) res *= a;
        a *= a;
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::map<char, int> cast{
        {'^', 3},
        {'*', 2}, {'/', 2},
        {'+', 1}, {'-', 1},
        {'(', 0}
    };

    std::string s;
    std::cin >> s;

    int n = s.size() - 1;

    std::vector<int> stk;
    std::string rev;
    for (int i = 0; i < n; i ++) {
        if (std::isdigit(s[i])) {
            rev.push_back(s[i]);
        } else if (s[i] == '(') {
            stk.push_back('(');
        } else if (s[i] == ')') {
            while (stk.size() && stk.back() != '(') {
                rev.push_back(stk.back());
                stk.pop_back();
            }
            if (stk.size() && stk.back() == '(') {
                stk.pop_back();
            }
        } else {
            while (stk.size() && cast[stk.back()] >= cast[s[i]]) {
                rev.push_back(stk.back());
                stk.pop_back();
            }
            stk.push_back(s[i]);
        }
    }
    while (stk.size()) {
        rev.push_back(stk.back());
        stk.pop_back();
    }

    n = rev.size(), s = rev;
    for (int i = 0; i < n; i ++) {
        if (std::isdigit(s[i])) {
            stk.push_back(s[i] - '0');
        } else {
            int b = stk[stk.size() - 1];
            int a = stk[stk.size() - 2];

            stk.pop_back();
            stk.pop_back();

            if (s[i] == '+') {
                stk.push_back(a + b);
            } else if (s[i] == '-') {
                stk.push_back(a - b);
            } else if (s[i] == '*') {
                stk.push_back(a * b);
            } else if (s[i] == '/') { 
                stk.push_back(a / b);
            } else {
                stk.push_back(qpow(a, b));
            }
        }
    }

    std::cout << stk.back() << '\n';

    return 0;
}
