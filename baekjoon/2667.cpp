#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 26;
int n;
int mat[MAX][MAX];
vector<int> answer;
// bool visited[MAX][MAX];
int cnt;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isInside(int x, int y) {
    return (x >= 1 && x <= n && y >= 1 && y <= n);
}

void dfs(int x, int y, int num) {
    mat[x][y] = num;
    cnt++;
    
    for (int i = 0; i < 4; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if (isInside(nextX, nextY) && mat[nextX][nextY] == 1) {
            dfs(nextX, nextY, num);
        }
    }
}

int main() {
    int danji = 2;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < n; j++) {
            mat[i][j + 1] = tmp[j] - '0';
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (mat[i][j] == 1) {
                cnt = 0;
                dfs(i, j, danji);
                danji++;

                answer.push_back(cnt);
            }
        }
    }

    sort(answer.begin(), answer.end());

    cout << danji - 2 << '\n';
    for (int ans : answer) {
        cout << ans << '\n';
    }

    return 0;
}