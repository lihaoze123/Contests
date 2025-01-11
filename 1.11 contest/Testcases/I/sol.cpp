#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, q;
    std::cin >> n >> m >> q;

    std::vector a(n + 1, std::vector(m + 1, 0));
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            std::cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            a[i][j] += a[i - 1][j];
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            a[i][j] += a[i][j - 1];
        }
    }

    while (q --) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        x1 --; 
        y1 --;

        std::cout << a[x2][y2] - a[x2][y1] - a[x1][y2] + a[x1][y1] << '\n';
    }

    return 0;
}
