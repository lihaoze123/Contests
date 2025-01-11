#include <bits/stdc++.h>
#include "testlib.h"

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int T = rnd.next(1, 100);
    std::cout << T << '\n';

    for (int i = 0; i < T; i++) {
        int N = rnd.next(10, 100000);
        int S = rnd.next(1, 100000000);
        std::cout << N << ' ' << S << '\n';

        std::vector<int> a(N);
        for (int i = 0; i < N; i++) {
            a[i] = rnd.next(1, 10000);
        }

        for (int i = 0; i < N; i++) {
            std::cout << a[i] << " ";
        }
        std::cout << '\n';
    }

    return 0;
}