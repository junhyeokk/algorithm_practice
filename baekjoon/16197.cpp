#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 22;
int n, m;
bool arr[MAX][MAX];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int answer = 1e9;

bool isIn(int x, int y) {
    return (x >= 1 && x <= n && y >= 1 && y <= m);
}

void go(int coin1x, int coin1y, int coin2x, int coin2y, int depth) {
    if (isIn(coin1x, coin1y) != isIn(coin2x, coin2y)) {
        answer = min(answer, depth);
        return;
    }
    if (!isIn(coin1x, coin1y) && !isIn(coin2x, coin2y)) return;
    if (depth == 10) return;

    if (isIn(coin1x, coin1y) && isIn(coin2x, coin2y)) {
        for (int i = 0; i < 4; i++) {
            int nextX1 = coin1x + dx[i];
            int nextY1 = coin1y + dy[i];
            int nextX2 = coin2x + dx[i];
            int nextY2 = coin2y + dy[i];

            if (!arr[nextX1][nextY1]) {
                nextX1 = coin1x;
                nextY1 = coin1y;
            }
            if (!arr[nextX2][nextY2]) {
                nextX2 = coin2x;
                nextY2 = coin2y;
            }

            go(nextX1, nextY1, nextX2, nextY2, depth + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int coin1_x, coin2_x, coin1_y, coin2_y;
    bool coinchk = false;
    memset(arr, true, sizeof(bool) * MAX * MAX);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string tmp;
        cin >> tmp;

        for (int j = 1; j <= m; j++) {
            if (tmp[j - 1] == 'o') {
                if (coinchk) {
                    coin2_x = i;
                    coin2_y = j;
                } else {
                    coin1_x = i;
                    coin1_y = j;
                    coinchk = true;
                }
                arr[i][j] = true;
            } else if (tmp[j - 1] == '#') {
                arr[i][j] = false;
            } else if (tmp[j - 1] == '.') {
                arr[i][j] = true;
            }
        }
    }

    go(coin1_x, coin1_y, coin2_x, coin2_y, 0);
    if (answer == 1e9) answer = -1;
    cout << answer << '\n';

    return 0;
}