#include "bits/stdc++.h"

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int H, W, X, Y;
    std::cin >> H >> W >> X >> Y;
    X--;
    Y--;

    std::vector<std::string> S(H);
    for (int i = 0; i < H; i++) {
        std::cin >> S[i];
    }

    auto valid = [&](int x, int y) {
        return x >= 0 && x < H && y >= 0 && y < W && S[x][y] != '#';
    };

    std::map<char, std::array<int, 2>> cast{
        {'U', {-1, 0}},
        {'D', {1, 0}},
        {'L', {0, -1}},
        {'R', {0, 1}}
    };

    std::string op;
    std::cin >> op;

    std::set<std::array<int, 2>> cnt;
    if (S[X][Y] == '@') {
        cnt.insert({X, Y});
    }

    for (auto c : op) {
        int nx = X + cast[c][0], ny = Y + cast[c][1];
        if (valid(nx, ny)) {
            X = nx, Y = ny;
            if (S[X][Y] == '@') {
                cnt.insert({X, Y});
            }
        }
    }

    std::cout << X + 1 << ' ' << Y + 1 << ' ' << cnt.size() << '\n';

    return 0;
}
