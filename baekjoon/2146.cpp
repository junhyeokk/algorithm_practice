#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 101;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dist[MAX][MAX];
int n;
int answer = 1e9;
queue<pair<int, int>> q;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool isInside(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

void findIsland(int x, int y, int num) {
    visited[x][y] = true;
    map[x][y] = num;

    bool isInQ = false;
    for (int i = 0; i < 4; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if (isInside(nextX, nextY) && !visited[nextX][nextY] && map[nextX][nextY] == 1) {
            findIsland(nextX, nextY, num);
        } else if (isInside(nextX, nextY) && map[nextX][nextY] == 0 && !isInQ) {
            q.push({x, y});
            dist[x][y] = 0;
            isInQ = true;
        }
    }
}

void bridge() {
    int counter = 1e9;
    while (!q.empty()) {
        int curX = q.front().first; int curY = q.front().second; q.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];

            if (isInside(nextX, nextY) && map[nextX][nextY] == 0 && !visited[nextX][nextY] && dist[nextX][nextY] == 0) {
                map[nextX][nextY] = map[curX][curY];
                dist[nextX][nextY] = dist[curX][curY] + 1;
                visited[nextX][nextY] = true;
                q.push({nextX, nextY});
            } else if (isInside(nextX, nextY) && dist[nextX][nextY] != 0 && visited[nextX][nextY] && map[nextX][nextY] != map[curX][curY]) {
                answer = min(dist[nextX][nextY] + dist[curX][curY], answer);
                counter = q.size();
            }
        }

        counter--;
        if (counter == 0) {
            break;
        }
    }

    cout << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(visited, 0, sizeof(bool) * MAX * MAX);
    memset(dist, 0, sizeof(int) * MAX * MAX);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    int island_count = 10001;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && map[i][j] == 1) {
                findIsland(i, j, island_count);
                island_count++;
            }
        }
    }

    bridge();

    return 0;
}