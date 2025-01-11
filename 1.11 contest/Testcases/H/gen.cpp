#include <bits/stdc++.h>
#include "testlib.h"

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int N = rnd.next(1, 50000);
    int Q = rnd.next(1, 200000);
    std::cout << N << ' ' << Q << '\n';

    std::vector<int> a(N);
    for (int i = 0; i < N; i ++) {
        a[i] = rnd.next(1, 1000000);
    }
    for (int i = 0; i < N; i ++) {
        std::cout << a[i] << '\n';
    }

    for (int i = 0; i < Q; i ++) {
        int l = rnd.next(1, N);
        int r = rnd.next(l, N);
        std::cout << l << ' ' << r << '\n';
    }

    return 0;
}