#include <bits/stdc++.h>

template <class T, class Cmp = std::less<T>>
struct RMQ {
    const Cmp cmp = Cmp(); 
    int n;
    std::vector<std::vector<T>> a;

    RMQ() {}
    RMQ(const std::vector<T> &v) {
        init(v);
    }

    void init(const std::vector<T> &v) {
        n = v.size();
        if (!n) {
            return;
        }

        const int lg = std::__lg(n);
        a.assign(lg + 1, std::vector<T>(n));

        for (int i = 0; i < n; i ++) {
            a[0][i] = v[i];
        }

        for (int j = 0; j < lg; j ++) {
            for (int i = 0; i + (1 << j) < n; i ++) {
                a[j + 1][i] = std::min(a[j][i], a[j][i + (1 << j)], cmp);
            } 
        }
    }

    T operator()(int l, int r) {
        assert(l <= r);
        int lg = std::__lg(r - l);
        T ans = std::min(a[lg][l], a[lg][r - (1 << lg)], cmp);
        return ans;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> a(N);
    for (int i = 0; i < N; i ++) {
        std::cin >> a[i];
    }

    RMQ<int, std::less<int>> min(a);
    RMQ<int, std::greater<int>> max(a);
    while (Q --) {
        int l, r;
        std::cin >> l >> r;
        l --;

        std::cout << max(l, r) - min(l, r) << '\n';
    }

    return 0;
}
