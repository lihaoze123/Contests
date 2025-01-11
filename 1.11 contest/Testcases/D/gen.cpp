#include <bits/stdc++.h>
#include "testlib.h"

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    std::cerr << std::fixed << std::setprecision(2);

    double x1 = (double)rnd.next(-100, 90);
    if (std::abs(x1) < 1e-4) x1 = 1;
    double x2 = (double)rnd.next((int)x1 + 1, 95);
    if (std::abs(x2) < 1e-4) x2 = 2;
    double x3 = (double)rnd.next((int)x2 + 1, 100);
    if (std::abs(x3) < 1e-4) x3 = 3;

    double b = -(x1 + x2 + x3);
    double c = x1 * x2 + x2 * x3 + x3 * x1;
    double d = -(x1 * x2 * x3);

    std::cout << "1 " << b << " " << c << " " << d << '\n';

    std::cerr << x1 << " " << x2 << " " << x3 << '\n';

    return 0;
}
