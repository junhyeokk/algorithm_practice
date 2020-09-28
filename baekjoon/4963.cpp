#include <iostream>
using namespace std;

const int MAX = 51;
int w, h;
int map[MAX][MAX];

int dx[] = {-1, 0, 0, 1, -1, 1, 1, -1};
int dy[] = {0, -1, 1, 0, -1, 1, -1, 1};

bool isInside(int x, int y) {
    return (x <= w && x >= 1 && y <= h && y >= 1);
}

void dfs(int x, int y, int num) {
    map[x][y] = num;

    for (int i = 0; i < 8; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if (isInside(nextX, nextY) && map[nextX][nextY] == 1) {
            dfs(nextX, nextY, num);
        }
    }
}

int main() {
    while (1) {
        cin >> h >> w;

        if (w == 0 && h == 0) break;

        for (int i = 1; i <= w; i++) {
            for (int j = 1; j <= h; j++) {
                cin >> map[i][j];
            }
        }

        int cnt = 2;

        for (int i = 1; i <= w; i++) {
            for (int j = 1; j <= h; j++) {
                if (map[i][j] == 1) {
                    dfs(i, j, cnt);
                    cnt++;
                }
            }
        }

        cout << cnt - 2 << '\n';
    }
    
    return 0;
}