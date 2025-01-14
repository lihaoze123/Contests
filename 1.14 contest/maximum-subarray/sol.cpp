#include "bits/stdc++.h"

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (int i = 0; i < n; i ++) {
        std::cin >> a[i];
    }

    std::vector<i64> s(n + 1);
    for (int i = 0; i < n; i ++) {
        s[i + 1] = s[i] + a[i];
    }

    i64 ans = *std::max_element(a.begin(), a.end());

    std::deque<int> q;
    for (int i = 0; i < n; i ++) {
        if (q.size() && q.front() < i - m + 1) {
            q.pop_front();
        }
        if (q.size()) {
            ans = std::max(ans, s[i + 1] - s[q.front()]);
        }
        while (q.size() && s[q.back()] >= s[i]) {
            q.pop_back();
        }
        q.push_back(i);
    }

    std::cout << ans << '\n';

    return 0;
}
