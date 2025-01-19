#include <bits/stdc++.h>

struct Trie {
    struct Node {
        std::array<int, 26> son;
        int cnt;
        Node() : son{}, cnt{} {}
    };

    std::vector<Node> t;

    Trie() {
        init();
    }

    void init() {
        t.assign(1, {});
    }

    int son(int u, char c) {
        return t[u].son[c - 'a'];
    }

    void insert(const std::string& s) {
        int p = 0;
        for (char c : s) {
            if (!son(p, c)) {
                t[p].son[c - 'a'] = t.size();
                t.push_back({});
            }
            p = son(p, c);
        }
        t[p].cnt ++;
    }

    int index(const std::string& s) {
        int p = 0;
        for (char c : s) {
            if (!son(p, c)) {
                return 0;
            }
            p = son(p, c);
        }
        return p;
    }

    int cnt(int u) {
        return t[u].cnt;
    }

    int cnt(const std::string& s) {
        int u = index(s);
        if (u) {
            return cnt(u);
        } else {
            return 0;
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<std::string> s(N);
    for (int i = 0; i < N; i ++) {
        std::cin >> s[i];
    }

    Trie trie;
    for (int i = 0; i < N; i ++) {
        trie.insert(s[i]);
    }

    int Q;
    std::cin >> Q;

    std::vector<std::string> pre(Q);
    for (int i = 0; i < Q; i ++) {
        std::cin >> pre[i];
    }

    for (int i = 0; i < Q; i ++) {
        std::vector<std::string> res;

        auto dfs = [&] (auto&& self, const std::string& cur) -> void {
            if (res.size() >= 8) {
                return;
            }
            int u = trie.index(cur);
            if (u == 0) {
                return;
            }
            if (trie.cnt(u)) {
                res.push_back(cur);
            }
            for (char c = 'a'; c <= 'z'; c ++) {
                if (trie.son(u, c)) {
                    self(self, cur + c);
                }
            }
        };

        dfs(dfs, pre[i]);

        int n = res.size();
        if (n == 0) {
            std::cout << pre[i] << '\n';
        } else {
            for (int j = 0; j < n; j ++) {
                std::cout << res[j] << " \n"[j == n - 1];
            }
        }
    }

    return 0;
}
