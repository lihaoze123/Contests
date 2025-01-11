#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i ++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    int ans = 0;
    for (int i = 0, j = 0; i < n; i ++) {
        while (j + 1 < n && a[j + 1] - a[i] <= k) {
            j ++;
        }
        ans = std::max(ans, j - i + 1);
    }

    std::cout << ans << '\n';
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
