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

    auto dfdx = [&] (double x) {
        return 3 * a * x * x + 2 * b * x + c;
    };

    for (double i = -100; i < 100; i += 0.5) {
        double lo = i, hi = i + 1;
        if (f(lo) * f(hi) < 0) {
            double x = (lo + hi) / 2;
            while (std::abs(f(x)) >= 1e-4) {
                x = x - f(x) / dfdx(x);
            }
            std::cout << x << ' ';
        }
    }

    return 0;
}
