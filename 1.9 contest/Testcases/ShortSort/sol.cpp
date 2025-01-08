#include "bits/stdc++.h"

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::string S, T;
    std::cin >> S >> T;

    if (std::multiset(S.begin(), S.end()) == std::multiset(T.begin(), T.end())) {
        std::cout << "YES" << '\n';
    } else {
        std::cout << "NO" << '\n';
    }

    return 0;
}

