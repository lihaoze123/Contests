#include <bits/stdc++.h>

using i64 = long long;

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
        return t[u].son[c - 'A'];
    }

    void insert(const std::string& s) {
        int p = 0;
        for (char c : s) {
            if (!son(p, c)) {
                t[p].son[c - 'A'] = t.size();
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

    Trie trie;

    std::string s;
    while (std::cin >> s) {
        trie.insert(s);
    }

    std::cout << trie.t.size() << '\n';

    return 0;
}