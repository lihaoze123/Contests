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
    for (int i = 0; i < n; i ++) {
        auto it = std::prev(std::upper_bound(a.begin(), a.end(), a[i] + k));
        ans = std::max(ans, int(it - a.begin()) - i + 1);
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
