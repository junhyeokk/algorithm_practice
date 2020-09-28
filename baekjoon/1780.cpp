#include <iostream>
using namespace std;

const int MAX = 2188;
int n;
int mat[MAX][MAX];
int minus_one = 0, plus_one = 0, zero = 0;

void go(int x, int y, int length) {
    int cur = mat[x][y];
    if (length == 1) {
        if (cur == -1) minus_one++;
        else if (cur == 1) plus_one++;
        else if (cur == 0) zero++;
        return;
    }

    bool break_flag = false;

    for (int i = x; i < x + length; i++) {
        for (int j = y; j < y + length; j++) {
            if (cur != mat[i][j]) {
                break_flag = true;
                break;
            }
        }
        if (break_flag) break;
    }

    if (!break_flag) {
        if (cur == -1) minus_one++;
        else if (cur == 1) plus_one++;
        else if (cur == 0) zero++;
    } else {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                go(x + length / 3 * i, y + length / 3 * j, length / 3);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mat[i][j];
        }
    }

    go(1, 1, n);
    cout << minus_one << '\n' << zero << '\n' << plus_one << '\n';

    return 0;
}