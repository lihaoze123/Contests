#include <bits/stdc++.h>
#include "testlib.h"

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int N = opt<int>("n");

    int n = rnd.next(1, N);
    std::cout << n << '\n';

    int cnt = 0;

    for (int i = 0; i < n; i ++) {
        int op = rnd.next(1, 3);
        if (op == 1) {
            int x = rnd.next(1, 100);
            std::cout << op << ' ' << x << '\n';
            cnt ++;
        } else if (op == 2) {
            if (cnt == 0) {
                op = 3;
            }
            std::cout << op << '\n';
            if (op == 2) {
                cnt --;
            }
        } else {
            std::cout << op << '\n';
        }
    }

}