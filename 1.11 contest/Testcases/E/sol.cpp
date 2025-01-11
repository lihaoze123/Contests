#include <bits/stdc++.h>

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

    i64 sum = std::accumulate(a.begin(), a.end(), 0LL);
    i64 max = *std::max_element(a.begin(), a.end());

    auto check = [&] (i64 x) {
        std::vector<i64> v;
        for (int i = 0; i < n; i ++) {
            if (v.empty() || v.back() + a[i] > x) {
                v.push_back(a[i]);
            } else {
                v.back() += a[i];
            }
        }
        return v.size() > m;
    };

    i64 res = *std::ranges::partition_point(std::ranges::views::iota(max, sum), check);
    std::cout << res << '\n';

    return 0;
}
