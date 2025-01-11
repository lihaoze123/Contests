#include <bits/stdc++.h>
#include "testlib.h"

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int n = rnd.next(1, 100000);
    std::cout << n << '\n';

    std::vector<int> a(n);
    for (int i = 0; i < n; i ++) {
        a[i] = rnd.next(0, 1000'000'000);
    }

    for (int i = 0; i < n; i ++) {
        std::cout << a[i] << " \n"[i == n - 1];
    }

    return 0;
}