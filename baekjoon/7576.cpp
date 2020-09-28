#include <iostream>
#include <queue>
using namespace std;

const int MAX = 1001;
int m, n;
int map[MAX][MAX];

bool isInside(int x, int y) {
    return (x >= 1 && x <= m && y >= 1 && y <= n);
}

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    bool flag = true;

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];

            if (map[i][j] == 0) flag = false;
        }
    }

    if (flag) {
        cout << "0\n";
        return 0;
    }

    queue<pair<int, int>> q;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (map[i][j] == 1) q.push({i, j});
        }
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];

            if (isInside(nextX, nextY) && map[nextX][nextY] == 0) {
                map[nextX][nextY] = map[x][y] + 1;
                q.push({nextX, nextY});
            }
        }
    }

    int cnt = -1;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cnt = max(cnt, map[i][j]);
            if (map[i][j] == 0) {
                cout << "-1\n";
                return 0;
            }
        }
    }

    cout << cnt - 1 << '\n';

    return 0;
}