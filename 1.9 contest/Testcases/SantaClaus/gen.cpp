#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int H = rnd.next(3, 100);
    int W = rnd.next(3, 100);
    
    // 创建网格
    vector<string> grid(H, string(W, '.'));
    
    // 设置边界为'#'
    for(int i = 0; i < H; i++) {
        grid[i][0] = grid[i][W-1] = '#';
    }
    for(int j = 0; j < W; j++) {
        grid[0][j] = grid[H-1][j] = '#';
    }
    
    // 随机放置一些'#'和'@'
    for(int i = 1; i < H-1; i++) {
        for(int j = 1; j < W-1; j++) {
            if(rnd.next(100) < 20) { // 20%概率放置'#'
                grid[i][j] = '#';
            } else if(rnd.next(100) < 30) { // 30%概率放置'@'
                grid[i][j] = '@';
            }
        }
    }
    
    // 随机选择起始位置(确保是'.'）
    int X, Y;
    do {
        X = rnd.next(1, H-2);
        Y = rnd.next(1, W-2);
    } while(grid[X][Y] != '.');
    
    // 生成移动指令
    string directions = "UDLR";
    int len = rnd.next(1, 10000);
    string T;
    for(int i = 0; i < len; i++) {
        T += directions[rnd.next(4)];
    }
    
    // 输出测试数据
    cout << H << " " << W << " " << X+1 << " " << Y+1 << endl;
    for(int i = 0; i < H; i++) {
        cout << grid[i] << endl;
    }
    cout << T << endl;
    
    return 0;
}