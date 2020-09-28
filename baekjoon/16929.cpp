#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 51;
int n, m;
char map[MAX][MAX];
bool visited[MAX][MAX];
bool answer = false;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool isInside(int x, int y) {
    return (x <= n && x >= 1 && y <= m && y >= 1);
}

void dfs(int x, int y, int prevX, int prevY) {
    if (answer) return;

    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if (isInside(nextX, nextY)) {
            if (!visited[nextX][nextY] && map[nextX][nextY] == map[x][y]) dfs(nextX, nextY, x, y);
            else if (visited[nextX][nextY] && map[nextX][nextY] == map[x][y] && (nextX != prevX || nextY != prevY)) {
                answer = true;
                return;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    memset(visited, 0, sizeof(bool) * MAX * MAX);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!visited[i][j]) {
                dfs(i, j, i, j);
            }
            
            if (answer) {
                cout << "Yes\n";
                return 0;
            }
        }
    }

    cout << "No\n";
    return 0;
}