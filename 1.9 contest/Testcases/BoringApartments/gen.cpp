#include <bits/stdc++.h>
#include "testlib.h"

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int t = rnd.next(1, 36);
    std::cout << t << '\n';

    for (int i = 0; i < t; i++) {
        int digit = rnd.next(1, 9);  // 生成 1-9 的数字
        int len = rnd.next(1, 4);    // 生成数字的长度 1-4
        
        // 生成由相同数字组成的数
        for (int j = 0; j < len; j++) {
            std::cout << digit;
        }
        std::cout << '\n';
    }

    return 0;
}