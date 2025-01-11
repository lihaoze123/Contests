#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, C;
    std::cin >> N >> C;

    std::vector<int> X(N);
    for (int i = 0; i < N; i ++) {
        std::cin >> X[i];
    }

    std::sort(X.begin(), X.end());

    auto check = [&] (int x) {
        int cnt = 1, now = 0;
        for (int i = 1; i < N; i ++) {
            if (X[i] - X[now] >= x) {
                cnt ++;
                now = i;
            } 
        }
        return cnt >= C;
    };

    int res = *std::ranges::partition_point(std::ranges::iota_view(0, 1000000000), check) - 1;
    std::cout << res << '\n';

    return 0;
}
