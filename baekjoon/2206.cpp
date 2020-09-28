#include <bits/stdc++.h>
using namespace std;

int n, m;
bool board[1001][1001];
int dist[1001][1001];
bool visited[1001][1001][2];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool isInside(int x, int y) {
    return (x >= 1 && x <= n && y >= 1 && y <= m);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    fill(dist[0], dist[0] + 1001 * 1001, 2e9);
    
    for (int i = 1; i <= n; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 1; j <= m; j++) {
            board[i][j] = tmp[j - 1] - '0';
        }
    }

    queue<pair<pair<int, int>, bool>> q;
    q.push({{1, 1}, false});
    dist[1][1] = 1;
    visited[1][1][0] = true;
    while (!q.empty()) {
        int curX = q.front().first.first;
        int curY = q.front().first.second;
        bool destructed = q.front().second;
        q.pop();

        if (curX == n && curY == m) break;

        for (int i = 0; i < 4; i++) {
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];

            if (isInside(nextX, nextY)) {
                if (!board[nextX][nextY]) {
                    if (!destructed && !visited[nextX][nextY][0]) {
                        dist[nextX][nextY] = dist[curX][curY] + 1;
                        visited[nextX][nextY][0] = true;
                        q.push({{nextX, nextY}, destructed});
                    } else if (destructed && !visited[nextX][nextY][1]) {
                        dist[nextX][nextY] = dist[curX][curY] + 1;
                        visited[nextX][nextY][1] = true;
                        q.push({{nextX, nextY}, destructed});
                    }
                } else if (board[nextX][nextY] && !destructed) {
                    dist[nextX][nextY] = dist[curX][curY] + 1;
                    q.push({{nextX, nextY}, true});
                }
            }
        }
    }

    if (dist[n][m] == 2e9) cout << "-1\n";
    else cout << dist[n][m] << '\n';

    return 0;
}