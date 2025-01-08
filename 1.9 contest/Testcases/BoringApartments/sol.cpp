#include "bits/stdc++.h"

using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;

    int cnt = 0;
    for (int i = 1; i <= 9; i ++) {
        for (int j = 1; j <= 4; j ++) {
            cnt += j;
            if (std::string(j, i + '0') == s) {
                std::cout << cnt << '\n';
                return;
            }
        }
    }

    std::cout << cnt << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t --) {
        solve();
    }

    return 0;
}
