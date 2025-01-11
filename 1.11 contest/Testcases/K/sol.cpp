#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> p;

    std::vector<std::array<int, 2>> add(n), query(m);
    for (auto &[x, c] : add) {
        std::cin >> x >> c;
        p.push_back(x);
    }
    for (auto &[l, r] : query) {
        std::cin >> l >> r;
        p.push_back(l);
        p.push_back(r);
    }

    std::sort(p.begin(), p.end());
    p.erase(std::unique(p.begin(), p.end()), p.end());
    n = p.size();

    std::unordered_map<int, int> cast;
    for (int i = 0; i < n; i ++) {
        cast[p[i]] = i;
    }

    std::vector<i64> a(n);
    for (auto &[x, c] : add) {
        a[cast[x]] += c;
    }

    std::vector<i64> s(n + 1);
    for (int i = 0; i < n; i ++) {
        s[i + 1] = s[i] + a[i];
    }

    for (auto &[l, r] : query) {
        std::cout << s[cast[r] + 1] - s[cast[l]] << '\n';
    }

    return 0;
}
