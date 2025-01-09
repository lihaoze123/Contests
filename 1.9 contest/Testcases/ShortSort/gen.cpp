#include <bits/stdc++.h>
#include "testlib.h"

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int N = rnd.next(1, 100);
    std::string S = rnd.next("[a-z]{" + std::to_string(N) + "}");
    std::string T = S;

    if (rnd.next(0, 100) >= 80) {
        int a = rnd.next(0, N - 1);
        int b = rnd.next(0, N - 1);
        std::swap(T[a], T[b]);
    } else {
        T = rnd.next("[a-z]{" + std::to_string(N) + "}");
    }

    std::cout << N << '\n';
    std::cout << S << '\n';
    std::cout << T << '\n';

    return 0;
}
