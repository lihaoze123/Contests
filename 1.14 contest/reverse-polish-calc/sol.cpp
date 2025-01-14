#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::vector<int> stk;
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
            } else {
                stk.push_back(a / b);
            }
        }
    }

    std::cout << stk.back() << '\n';

    return 0;
}
