#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    std::cin >> N >> K;

    std::string S;
    std::cin >> S;

    i64 ans = 0;
    for (int i = 0, j = 0; i < N; i ++) {
        if (S[i] != 'O') {
            continue;
        }
        j = i;
        while (j + 1 < N && S[j + 1] == 'O') {
            j ++;
        }
        ans += (j - i + 1) / K;
        i = j;
    }

    std::cout << ans << '\n';

    return 0;
}
