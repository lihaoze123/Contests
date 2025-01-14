#include "testlib.h"

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1, 100'000, "n");
    inf.readEoln();

    int cnt = 0;
    for (int i = 0; i < n; i ++) {
        int op = inf.readInt(1, 3, "op");

        if (op == 1) {
            inf.readSpace();
            inf.readInt(1, 100, "x");
            inf.readEoln();
            cnt ++;
        } else if (op == 2) {
            if (cnt == 0) {
                quitf(_fail, "Pop operation on an empty stack");
            }
            inf.readEoln();
            cnt --;
        } else {
            inf.readEoln();
        }
    }

    inf.readEof();
}