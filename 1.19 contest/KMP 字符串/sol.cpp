#include <bits/stdc++.h>

using i64 = long long;

std::vector<int> KMP(const std::string& s) {
    int n = s.size();
    std::vector<int> f(n + 1);
    for (int i = 1, j = 0; i < n; i ++) {
        while (j && s[i] != s[j]) {
            j = f[j];
        }
        j += (s[i] == s[j]);
        f[i + 1] = j;
    }
    return f;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::string P, S;

    std::cin >> N >> P >> M >> S;

    auto f = KMP(P);

    for (int i = 0, j = 0; i < M; i ++) {
        while (j && S[i] != P[j]) {
            j = f[j];
        }
        j += (S[i] == P[j]);
        if (j == N) {
            std::cout << i - j + 1 << ' ';
            j = f[j];
        }
    }

    return 0;
}
