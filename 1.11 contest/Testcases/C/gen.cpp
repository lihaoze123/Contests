#include <bits/stdc++.h>
#include "testlib.h"

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int T = rnd.next(1, 100);
    std::cout << T << '\n';

    for (int i = 0; i < T; i++) {
        int N = rnd.next(1, 100000);
        int K = rnd.next(1, 1000'000'000);
        std::cout << N << ' ' << K << '\n';

        std::vector<int> a(N);
        for (int j = 0; j < N; j++) {
            a[j] = rnd.next(1, 1000'000'000);
        }
        std::sort(a.begin(), a.end());
        for (int j = 0; j < N; j++) {
            std::cout << a[j] << ' ';
        }
        std::cout << '\n';
    }
}