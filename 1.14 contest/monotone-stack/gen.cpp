#include <bits/stdc++.h>
#include "testlib.h"

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int n = opt<int>("n");
    int max_val = opt<int>("max_val");
    int min_val = opt<int>("min_val");

    std::cout << n << '\n';

    for (int i = 0; i < n; i++) {
        std::cout << rnd.next(1, max_val) << " \n"[i == n - 1];
    }

    return 0;
}
