#include <iostream>
using namespace std;

const int MAX = 50;
int n, m;
bool mat[MAX][MAX];
bool target[MAX][MAX];
int cnt = 0;

void swap_mat(int x, int y) {
    if (mat[x][y] == target[x][y]) return;

    cnt++;
    for (int i = x; i <= x + 2; i++) {
        for (int j = y; j <= y + 2; j++) {
            mat[i][j] = !mat[i][j];
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;

        for (int j = 0; j < m; j++) {
            if (tmp[j] == '0') {
                mat[i][j] = false;
            } else {
                mat[i][j] = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;

        for (int j = 0; j < m; j++) {
            if (tmp[j] == '0') {
                target[i][j] = false;
            } else {
                target[i][j] = true;
            }
        }
    }

    if (n < 3 || m < 3) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] != target[i][j]) {
                    cout << -1 << '\n';
                    return 0;
                }
            }
        }
    }

    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 2; j++) {
            swap_mat(i, j);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] != target[i][j]) {
                cout << -1 << '\n';
                return 0;
            }
        }
    }

    cout << cnt << '\n';
    return 0;
}