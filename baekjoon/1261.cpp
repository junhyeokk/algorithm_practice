#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 101;
bool graph[MAX][MAX];
int dist[MAX][MAX];
int n, m;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool isInside(int x, int y) {
    return (x >= 1 && x <= m && y >= 1 && y <= n);
}

void bfs() {
    queue<pair<int, int>> q;
    q.push({1, 1});
    dist[1][1] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];

            if (isInside(nextX, nextY)) {
                if (graph[nextX][nextY]) {
                    if (dist[nextX][nextY] > dist[x][y] + 1) {
                        dist[nextX][nextY] = dist[x][y] + 1;
                        q.push({nextX, nextY});
                    }
                } else {
                    if (dist[nextX][nextY] > dist[x][y]) {
                        dist[nextX][nextY] = dist[x][y];
                        q.push({nextX, nextY});
                    }
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        string tmp;
        cin >> tmp;

        for (int j = 1; j <= n; j++) {
            if (tmp[j - 1] == '0') {
                graph[i][j] = false;
            } else {
                graph[i][j] = true;
            }
        }
    }

    fill(dist[0], dist[0] + MAX * MAX, 1e9);
    bfs();
    // for (int i = 1; i <= m; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << dist[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    cout << dist[m][n] << '\n';

    return 0;
}