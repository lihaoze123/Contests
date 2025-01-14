#include "bits/stdc++.h"

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i ++) {
        std::cin >> a[i];
    }

    std::vector<int> stk;
    for (int i = 0; i < n; i ++) {
        while (stk.size() && stk.back() >= a[i]) {
            stk.pop_back();
        }
        if (stk.empty()) {
            std::cout << -1 << ' ';
        } else {
            std::cout << stk.back() << ' ';
        }
        stk.push_back(a[i]);
    }

    return 0;
}