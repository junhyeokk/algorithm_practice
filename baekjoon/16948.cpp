#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 201;
int n;
int chess[MAX][MAX];
int r1, c1, r2, c2;
int dy[] = {-1, -1, 1, 1, -2, 2};
int dx[] = {2, -2, 2, -2, 0, 0};

bool isInside(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

int main() {
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;

    fill(chess[0], chess[0] + MAX * MAX, 1e9);

    queue<pair<int, int>> q;
    q.push({r1, c1});
    chess[r1][c1] = 0;

    while (!q.empty()) {
        auto pos = q.front();
        q.pop();

        for (int j = 0; j < 6; j++) {
            int nextX = pos.first + dx[j];
            int nextY = pos.second + dy[j];

            if (isInside(nextX, nextY) && chess[nextX][nextY] > chess[pos.first][pos.second] + 1) {
                chess[nextX][nextY] = chess[pos.first][pos.second] + 1;
                q.push({nextX, nextY});
            }
        }
    }

    if (chess[r2][c2] == 1e9) {
        cout << -1 << '\n';
    } else {
        cout << chess[r2][c2] << '\n';
    }

    return 0;
}