#include <bits/stdc++.h>
#include "testlib.h"

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int N = rnd.next(1, 100);
    char c1 = rnd.next("[a-z]")[0];
    char c2 = rnd.next("[a-z]")[0];

    std::cout << N << ' ' << c1 << ' ' << c2 << '\n';
    std::cout << rnd.next("[a-z]{" + std::to_string(N) + "}") << '\n';

    return 0;
}