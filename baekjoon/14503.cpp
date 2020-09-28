#include <bits/stdc++.h>
using namespace std;

const int MAX = 51;
bool cleaned[MAX][MAX];
int area[MAX][MAX];
int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int cnt = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x, y, dir;

    cin >> n >> m;
    cin >> x >> y >> dir;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> area[i][j];
        }
    }

    x++;y++;
    while (1) {
        cleaned[x][y] = true;
        // cnt++;

        dir = (dir == 0) ? 3 : dir - 1;
        int nextX = x + dx[dir];
        int nextY = y + dy[dir];
        if (area[nextX][nextY] == 0 && !cleaned[nextX][nextY]) {
            x = nextX;
            y = nextY;
            continue;
        }

        dir = (dir == 0) ? 3 : dir - 1;
        nextX = x + dx[dir];
        nextY = y + dy[dir];
        if (area[nextX][nextY] == 0 && !cleaned[nextX][nextY]) {
            x = nextX;
            y = nextY;
            continue;
        }

        dir = (dir == 0) ? 3 : dir - 1;
        nextX = x + dx[dir];
        nextY = y + dy[dir];
        if (area[nextX][nextY] == 0 && !cleaned[nextX][nextY]) {
            x = nextX;
            y = nextY;
            continue;
        }

        dir = (dir == 0) ? 3 : dir - 1;
        nextX = x + dx[dir];
        nextY = y + dy[dir];
        if (area[nextX][nextY] == 0 && !cleaned[nextX][nextY]) {
            x = nextX;
            y = nextY;
            continue;
        }

        // 뒤로가기
        int back_dir = (dir + 2) % 4;
        nextX = x + dx[back_dir];
        nextY = y + dy[back_dir];
        if (area[nextX][nextY] == 0) {
            x = nextX;
            y = nextY;
            continue;
        } else {
            break;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (cleaned[i][j]) cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}