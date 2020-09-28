#include <iostream>
using namespace std;

const int MAX = 21;
bool visited[26];
char board[MAX][MAX];
int r, c;
int answer = 0;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool isInside(int x, int y) {
    return (x >= 1 && x <= r && y >= 1 && y <= c);
}

void dfs(int x, int y, int cnt) {
    for (int i = 0; i < 4; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if (isInside(nextX, nextY) && !visited[board[nextX][nextY] - 'A']) {
            visited[board[nextX][nextY] - 'A'] = true;
            dfs(nextX, nextY, cnt + 1);
            visited[board[nextX][nextY] - 'A'] = false;
        }
    }

    answer = max(answer, cnt);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> board[i][j];
        }
    }

    visited[board[1][1] - 'A'] = true;
    dfs(1, 1, 1);
    cout << answer << '\n';

    return 0;
}