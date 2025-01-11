#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << std::fixed << std::setprecision(2);

    double a, b, c, d;
    std::cin >> a >> b >> c >> d; 

    auto f = [&] (double x) {
        return a * x * x * x + b * x * x + c * x + d;
    };

    auto check = [&] (double lo, double hi) {
        return f(lo) * f(hi) < 0;
    };

    for (double i = -100; i <= 100; i += 0.9999) {
        double lo = i, hi = i + 1;
        if (check(lo, hi)) {
            while (hi - lo >= 1e-4) {
                double mid = (lo + hi) / 2;
                if (check(mid, hi)) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }
            std::cout << lo << ' ';
        }
    }

    return 0;
}
