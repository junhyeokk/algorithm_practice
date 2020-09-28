#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;

struct Point {
    int x, y;
};

const int MAX = 101;
int n, m;
int map[MAX][MAX];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isInside(int x, int y) {
    return (x >= 1 && x <= n && y >= 1 && y <= m);
}

void bfs(int startX, int startY) {
    queue<Point> q;
    q.push({startX, startY});
    map[startX][startY] = 1;

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];

            if (isInside(nextX, nextY) && map[nextX][nextY] == 0) {
                map[nextX][nextY] = map[x][y] + 1;

                if (nextX == n && nextY == m) return;
                q.push({nextX, nextY});
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        string tmp;
        cin >> tmp;

        for (int j = 1; j <= m; j++) {
            map[i][j] = tmp[j - 1] - '1';
        }
    }

    bfs(1, 1);
    cout << map[n][m] << endl;

    return 0;
}