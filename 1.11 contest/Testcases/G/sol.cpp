#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i ++) {
        std::cin >> a[i];
    }

    std::vector<int> tmp(n);
    std::function<i64(int, int)> inversion = [&] (int l, int r) -> i64 {
        if (r - l == 1) {
            return 0;
        }

        int mid = (l + r + 1) / 2;
        i64 res = inversion(l, mid) + inversion(mid, r);

        int i = l, j = mid, k = 0;
        while (i < mid && j < r) {
            if (a[i] <= a[j]) {
                tmp[k ++] = a[i ++];
            } else {
                res += mid - i;
                tmp[k ++] = a[j ++];
            }
        }

        while (i < mid) {
            tmp[k ++] = a[i ++];
        }
        while (j < r) {
            tmp[k ++] = a[j ++];
        }

        for (int i = 0; i < k; i ++) {
            a[i + l] = tmp[i];
        }

        return res;
    };

    i64 res = inversion(0, n);
    std::cout << res << '\n';

    return 0;
}
