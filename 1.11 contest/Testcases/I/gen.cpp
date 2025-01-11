#include <bits/stdc++.h>
#include "testlib.h"

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int n = rnd.next(1, 1000);
    int m = rnd.next(1, 1000);
    int q = rnd.next(1, 1000);
    std::cout << n << ' ' << m << ' ' << q << '\n';

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            std::cout << rnd.next(0, 1000) << " \n"[j == m - 1];
        }
    }

    for (int i = 0; i < q; i ++) {
        int x1 = rnd.next(1, n);
        int y1 = rnd.next(1, m);
        int x2 = rnd.next(x1, n);
        int y2 = rnd.next(y1, m);
        std::cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
    }

    return 0;
}