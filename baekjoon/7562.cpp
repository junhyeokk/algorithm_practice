#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 301;
int i;
int map[MAX][MAX];

int dx[] = {2, -2, 2, -2, 1, -1, 1, -1};
int dy[] = {1, 1, -1, -1, 2, 2, -2, -2};

bool isInside(int x, int y) {
    return (x >= 0 && x < i && y >= 0 && y < i);
}

int main() {
    int t;
    int startX, startY, targetX, targetY;
    queue<pair<int, int>> q;
    cin >> t;

    while (t--) {
        cin >> i;
        cin >> startX >> startY;
        cin >> targetX >> targetY;

        memset(map, 0, sizeof(int) * MAX * MAX);
        while (!q.empty()) {
            q.pop();
        }

        q.push({startX, startY});
        map[startX][startY] = 1;

        bool flag = false;
        
        while (!q.empty()) {
            if (flag) break;

            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 8; i++) {
                int nextX = x + dx[i];
                int nextY = y + dy[i];

                if (isInside(nextX, nextY) && map[nextX][nextY] == 0) {
                    map[nextX][nextY] = map[x][y] + 1;
                    q.push({nextX, nextY});
                    
                    if (nextX == targetX && nextY == targetY) {
                        flag = true;
                        break;
                    }
                }
            }
        }

        cout << map[targetX][targetY] - 1 << '\n';
    }

    return 0;
}