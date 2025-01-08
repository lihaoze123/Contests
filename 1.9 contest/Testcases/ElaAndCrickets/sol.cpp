#include "bits/stdc++.h"

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::array<int, 2>> p(3);
    for (int i = 0; i < 3; i ++) {
        std::cin >> p[i][0] >> p[i][1];
    }

    int x, y;
    std::cin >> x >> y;

    auto valid = [&] (int a, int b) {
        return 1 <= a && a <= n && 1 <= b && b <= n;
    };

    std::vector dx{1, -1, 0, 0, 0};
    std::vector dy{0, 0, 1, -1, 0};

    std::map<int, std::map<int, bool>> vis;
    for (int i = 0; i < 3; i ++) {
        vis[p[i][0]][p[i][1]] = true;
    }

    std::array<int, 2> t{};
    for (auto &[a, b] : p) {
        int cnt = 0;
        for (int i = 0; i < 4; i ++) {
            if (valid(a + dx[i], b + dy[i]) && vis[a + dx[i]][b + dy[i]]) {
                cnt ++;
            }
        } 
        if (cnt == 2) {
            t = { a, b };
        }
    }

    if (std::set{std::array{1, 1}, {1, n}, {n, 1}, {n, n}}.contains(t)) {
        if (x == t[0] || y == t[1]) {
            std::cout << "YES" << '\n';
        } else {
            std::cout << "NO" << '\n';
        }
        return;
    }

    for (int i = 0; i < 5; i ++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (valid(nx, ny) && (t[0] - nx) % 2 == 0 && (t[1] - ny) % 2 == 0) {
            std::cout << "YES" << '\n';
            return;
        }
    }

    std::cout << "NO" << '\n';
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
