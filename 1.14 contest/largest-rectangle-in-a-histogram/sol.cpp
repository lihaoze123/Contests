#include <bits/stdc++.h>

using i64 = long long;

void solve(int n) {
    std::vector<int> h(n);
    for (int i = 0; i < n; i ++) {
        std::cin >> h[i];
    }
    h.push_back(0);

    std::vector<std::array<int, 2>> stk;
    stk.push_back({1, h[0]});

    i64 ans = 0;
    for (int i = 1; i <= n; i ++) {
        if (h[i] > stk.back()[1]) {
            stk.push_back({1, h[i]});
            ans = std::max(ans, 1LL * h[i]);
        } else {
            int w = 0;
            while (stk.size() && stk.back()[1] >= h[i]) {
                w += stk.back()[0];
                ans = std::max(ans, 1LL * w * stk.back()[1]);
                stk.pop_back();
            }
            stk.push_back({w + 1, h[i]});
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    while (std::cin >> n, n) {
        solve(n);
    }

    return 0;
}
