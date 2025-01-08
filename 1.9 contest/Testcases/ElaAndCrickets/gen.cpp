#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int t = rnd.next(1, (int)1e4);  // 测试组数
    cout << t << "\n";

    while (t--) {
        int n = rnd.next(4, (int)1e5);  // 棋盘大小
        cout << n << "\n";
        
        // 随机选择L形状的类型（0-3）
        int type = rnd.next(0, 3);
        int r1, c1, r2, c2, r3, c3;
        
        // 随机选择基准点
        r1 = rnd.next(1, n-1);  // 确保有空间放置L形
        c1 = rnd.next(1, n-1);
        
        // 根据类型生成L形
        if (type == 0) {  // ┗
            r2 = r1;
            c2 = c1 + 1;
            r3 = r1 + 1;
            c3 = c1;
        } else if (type == 1) {  // ┏
            r2 = r1;
            c2 = c1 + 1;
            r3 = r1 - 1;
            c3 = c1;
        } else if (type == 2) {  // ┓
            r2 = r1 + 1;
            c2 = c1;
            r3 = r1;
            c3 = c1 - 1;
        } else {  // ┛
            r2 = r1 - 1;
            c2 = c1;
            r3 = r1;
            c3 = c1 - 1;
        }
        
        // 如果坐标超出边界，进行调整
        if (r2 < 1 || r2 > n || c2 < 1 || c2 > n ||
            r3 < 1 || r3 > n || c3 < 1 || c3 > n) {
            r1 = rnd.next(2, n-1);
            c1 = rnd.next(2, n-1);
            if (type == 0) {
                r2 = r1; c2 = c1 - 1; r3 = r1 - 1; c3 = c1;
            } else if (type == 1) {
                r2 = r1; c2 = c1 - 1; r3 = r1 + 1; c3 = c1;
            } else if (type == 2) {
                r2 = r1 - 1; c2 = c1; r3 = r1; c3 = c1 + 1;
            } else {
                r2 = r1 + 1; c2 = c1; r3 = r1; c3 = c1 + 1;
            }
        }
        
        cout << r1 << " " << c1 << " " << r2 << " " << c2 << " " << r3 << " " << c3 << "\n";
        
        // 生成目标位置
        int x = rnd.next(1, n);
        int y = rnd.next(1, n);
        cout << x << " " << y << "\n";
    }

    return 0;
}