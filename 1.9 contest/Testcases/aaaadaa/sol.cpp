#include "bits/stdc++.h"

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    char c1, c2;

    std::cin >> N >> c1 >> c2;

    std::string S;
    std::cin >> S;

    for (int i = 0; i < N; ++ i) {
        if (S[i] == c1) {
            std::cout << c1;
        } else {
            std::cout << c2;
        }
    }

    return 0;
}

