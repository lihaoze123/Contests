#include "bits/stdc++.h"

using i64 = long long;

void solve(int A, int B, int C) {
    std::vector<std::string> a(A), b(B), c(C);

    for (int i = 0; i < A; i ++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < B; i ++) {
        std::cin >> b[i];
    }
    for (int i = 0; i < C; i ++) {
        std::cin >> c[i];
    }

    std::set<std::string> s1(a.begin(), a.end()), s2(c.begin(), c.end());

    std::vector<std::string> ans;
    for (int i = 0; i < B; i ++) {
        if (s1.count(b[i]) && !s2.count(b[i])) {
            ans.push_back(b[i]);
        }
    }

    if (ans.size() == 0) {
        std::cout << "No enemy spy" << '\n';
        return;
    }

    for (int i = 0; i < ans.size(); i ++) {
        std::cout << ans[i] << " \n"[i == ans.size() - 1];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int A, B, C;
    while (std::cin >> A >> B >> C) {
        solve(A, B, C);
    }

    return 0;
}
