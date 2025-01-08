#include <bits/stdc++.h>
#include "testlib.h"

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int t = rnd.next(1, 1000);

    for (int i = 0; i < t; i ++) {
        int A = rnd.next(1, 1000);
        int B = rnd.next(1, 1000);
        int C = rnd.next(1, 1000);

        std::cout << A << " " << B << " " << C << '\n';

        std::vector<std::string> a(A);
        for (int j = 0; j < A; j ++) {
            a[j] = rnd.next("[a-z]{1,10}");
        }

        std::vector<std::string> b(B);
        for (int j = 0; j < B; j ++) {
            b[j] = rnd.next("[a-z]{1,10}");
        }

        std::vector<std::string> c(C);
        for (int j = 0; j < C; j ++) {
            c[j] = rnd.next("[a-z]{1,10}");
        }

        for (int j = 0; j < A; j ++) {
            std::cout << a[j] << " \n"[j == A - 1];
        }
        for (int j = 0; j < B; j ++) {
            std::cout << b[j] << " \n"[j == B - 1];
        }
        for (int j = 0; j < C; j ++) {
            std::cout << c[j] << " \n"[j == C - 1];
        }
    }

    return 0;
}