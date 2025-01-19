#include <bits/stdc++.h>

using i64 = long long;

bool isprime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int findPrime(int n) {
    while (!isprime(n)) {
        n++;
    }
    return n;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    const int P = findPrime(rng() % 900'000'000 + 100'000'000);

    int n, m;
    std::cin >> n >> m;

    std::string s;
    std::cin >> s;

    std::vector<int> h(n + 1), p(n + 1);
    for (int i = 0; i < n; i ++) {
        h[i + 1] = (13331LL * h[i] + s[i]) % P;
    }
    p[0] = 1;
    for (int i = 0; i < n; i ++) {
        p[i + 1] = 13331LL * p[i] % P;
    }

    auto get = [&] (int l, int r) {
        return (h[r] + 1LL * (P - h[l]) * p[r - l]) % P;
    };

    while (m --) {
        int l1, r1, l2, r2;
        std::cin >> l1 >> r1 >> l2 >> r2;
        l1 --;
        l2 --;

        if (get(l1, r1) == get(l2, r2)) {
            std::cout << "Yes" << '\n';
        } else {
            std::cout << "No" << '\n';
        }
    }

    return 0;
}
