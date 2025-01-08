#include <bits/stdc++.h>
#include "testlib.h"

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int N = rnd.next(1, 100);
    std::string S = rnd.next("[a-z]{" + std::to_string(N) + "}");
    std::string T = S;

    if (rnd.next(0, 1)) {
        shuffle(T.begin(), T.end());
    } else {
        T = rnd.next("[a-z]{" + std::to_string(N) + "}");
    }

    std::cout << N << '\n';
    std::cout << S << '\n';
    std::cout << T << '\n';

    return 0;
}