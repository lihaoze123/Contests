#include <bits/stdc++.h>
#include "testlib.h"

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int n = rnd.next(1, 100000);
    int m = rnd.next(1, 100000);
    std::cout << n << ' ' << m << '\n';
    
    for (int i = 0; i < n; i ++) {
        std::cout << rnd.next(1, 1000000000) << ' ' << rnd.next(1, 10000) << '\n';
    }

    for (int i = 0; i < m; i ++) {
        int l = rnd.next(1, 1000000000);
        int r = rnd.next(l, 1000000000);
        std::cout << l << ' ' << r << '\n';
    }

    return 0;
}
