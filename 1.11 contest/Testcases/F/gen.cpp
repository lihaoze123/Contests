#include <bits/stdc++.h>
#include "testlib.h"

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int N = rnd.next(2, 100000);
    int C = rnd.next(2, N);

    std::cout << N << ' ' << C << '\n';

    std::vector<int> a(N);
    for (int i = 0; i < N; i ++) {
        a[i] = rnd.next(0, 1000'000'000);
    }

    for (int i = 0; i < N; i ++) {
        std::cout << a[i] << '\n';
    }

    return 0;
}