#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> stk1, stk2;
    while (n --) {
        int op, x;
        std::cin >> op;

        if (op == 1) {
            std::cin >> x;
            stk1.push_back(x);

            if (stk2.size()) {
                if (stk2.back() >= x) {
                    stk2.push_back(x);
                } else {
                    stk2.push_back(stk2.back());
                }
            } else {
                stk2.push_back(x);
            }
        } else if (op == 2) {
            std::cout << stk2.back() << '\n';
            stk1.pop_back();
            stk2.pop_back();
        } else {
            if (stk2.size()) {
                std::cout << stk2.back() << '\n';
            } else {
                std::cout << -1 << '\n';
            }
        }
    }

    return 0;
}
