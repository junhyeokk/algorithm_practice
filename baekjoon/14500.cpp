#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 501;
int n, m;
int arr[MAX][MAX];
int biggest = -1;
bool visited[MAX][MAX];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool isIn(int x, int y) {
    return (x >= 1 && x <= n && y >= 1 && y <= m);
}

void go(int x, int y, int sum, int depth) {
    if (depth == 4) {
        biggest = max(biggest, sum);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if (isIn(nextX, nextY) && !visited[nextX][nextY]) {
            visited[nextX][nextY] = true;
            go(nextX, nextY, sum + arr[nextX][nextY], depth + 1);
            visited[nextX][nextY] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    memset(visited, 0, sizeof(bool) * MAX * MAX);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            visited[i][j] = true;
            go(i, j, arr[i][j], 1);
            visited[i][j] = false;

            if (isIn(i + 2, j + 1)) {
                biggest = max(biggest, arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 1][j + 1]);
                biggest = max(biggest, arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j + 1] + arr[i + 1][j]);
            }
            if (isIn(i + 1, j + 2)) {
                biggest = max(biggest, arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1]);
                biggest = max(biggest, arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2] + arr[i][j + 1]);
            }
        }
    }

    cout << biggest << '\n';

    return 0;
}