#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int N, S;
    std::cin >> N >> S;

    std::vector<int> a(N);
    for (int i = 0; i < N; i ++) {
        std::cin >> a[i];
    }

    std::vector<int> s(N + 1);
    for (int i = 0; i < N; i ++) {
        s[i + 1] = s[i] + a[i];
    }

    int ans = INT_MAX;
    for (int i = 1, j = 1; i <= N; i ++) {
        while (j + 1 <= N && s[j] - s[i - 1] < S) {
            j ++;
        }
        if (s[j] - s[i - 1] >= S) {
            ans = std::min(ans, j - i + 1);
        }
    }

    if (ans == INT_MAX) {
        std::cout << 0 << '\n';
    } else {
        std::cout << ans << '\n';
    }
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
