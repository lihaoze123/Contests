#include <bits/stdc++.h>

struct Trie {
    struct Node {
        std::array<int, 2> son;
        Node() : son{} {}
    };
    
    std::vector<Node> t;
    
    Trie() {
        init();
    }
    
    void init() {
        t.assign(1, {});
    }
    
    int& son(int u, int bit) {
        return t[u].son[bit];
    }
    
    void insert(int x) {
        int p = 0;
        for (int i = 30; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (!son(p, bit)) {
                son(p, bit) = t.size();
                t.push_back({});
            }
            p = son(p, bit);
        }
    }
    
    int query(int x) {
        int p = 0;
        int res = 0;
        for (int i = 30; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (son(p, bit ^ 1)) {
                p = son(p, bit ^ 1);
                res |= 1 << i;
            } else {
                p = son(p, bit);
            }
        }
        return res;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    Trie trie;
    for (int i = 0; i < n; i++) {
        trie.insert(a[i]);
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = std::max(ans, trie.query(a[i]));
    }
    
    std::cout << ans << '\n';
    
    return 0;
}
