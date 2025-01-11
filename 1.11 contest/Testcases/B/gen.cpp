#include <bits/stdc++.h>
#include "testlib.h"

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int N = rnd.next(1, 100000);
    int K = rnd.next(1, 10);
    std::cout << N << ' ' << K << '\n';

    std::string S(N, 'O');
    for (int i = 0; i < N; i++) {
        S[i] = rnd.next(0, 1) ? 'O' : 'X';
    }
    std::cout << S << '\n';

    return 0;
}