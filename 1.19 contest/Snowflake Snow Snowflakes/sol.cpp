#include <bits/stdc++.h>

using u64 = unsigned long long;

struct Hash {
    std::size_t operator()(const std::array<int, 6>& x) const {
        static std::vector<u64> p(7);

        p[0] = 1;
        for (int i = 0; i < 6; i ++) {
            p[i + 1] = 10 * p[i]; 
        }

        auto calc = [&] (std::array<int, 12>& a) {
            int i = 0, j = 1;
            while (i < 6 && j < 6) {
                int k = 0;
                while (k + 1 < 6 && a[i + k] == a[j + k]) {
                    k ++;
                }

                if (k == 6) {
                    break;
                }

                if (a[i + k] > a[j + k]) {
                    i = i + k + 1;
                    if (i == j) {
                        i ++;
                    }
                } else {
                    j = j + k + 1;
                    if (i == j) {
                        j ++;
                    }
                }
            }

            int k = std::min(i, j);

            u64 res = 0;
            for (int i = 0; i < 6; i ++) {
                res += a[i + k] * p[i];
            }

            return res;
        };

        std::array<int, 12> a, b;
        for (int i = 0; i < 6; i ++) {
            a[i] = a[i + 6] = x[i];
            b[12 - i - 1] = b[12 - (i + 6) - 1] = x[i];
        }

        u64 res = calc(a) * calc(b);
        return res;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::array<int, 6>> a(n);
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < 6; j ++) {
            std::cin >> a[i][j];
        }
    }

    Hash hash;
    std::unordered_set<u64> set;

    bool ok = false;
    for (int i = 0; i < n; i ++) {
        if (set.count(hash(a[i]))) {
            ok = true;
            break;
        }
        set.insert(hash(a[i]));
    }

    if (ok) {
        std::cout << "Twin snowflakes found." << '\n';
    } else {
        std::cout << "No two snowflakes are alike." << '\n';
    }

    return 0;
}