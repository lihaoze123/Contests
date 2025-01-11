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

    for (double i = -100; i < 100; i += 0.01) {
        double lo = i, hi = i + 0.01;
        if (f(lo) * f(hi) < 0) {
            std::cout << (lo + hi) / 2 << ' ';
        }
    }

    return 0;
}
