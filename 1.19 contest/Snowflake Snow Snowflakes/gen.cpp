#include <bits/stdc++.h>
#include "testlib.h"

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    bool rand = opt<bool>("rand");
    int max_val = rand ? 10'000'000 : opt<int>("max_val");
    int min_val = rand ? 0 : opt<int>("min_val");

    int n = rand ? rnd.next(1, opt<int>("n")) : opt<int>("n");
    std::cout << n << '\n';

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < 6; j ++) {
            std::cout << rnd.next(min_val, max_val) << " \n"[j == 5];
        }
    }
}