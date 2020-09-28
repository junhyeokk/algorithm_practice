#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 9;
int n, m;
char lab[MAX][MAX];
vector<pair<int, int>> v;
int answer = 0;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
bool visited[MAX][MAX];

bool isInside(int x, int y) {
    return (x > 0 && x <= n && y > 0 && y <= m);
}


void bfs() {
    queue<pair<int, int>> q;
    for (auto pp : v) {
        q.push(pp);
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];

            if (isInside(nextX, nextY) && lab[nextX][nextY] == 0 && !visited[nextX][nextY]) {
                q.push({nextX, nextY});
                visited[nextX][nextY] = true;
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (lab[i][j] == 0 && !visited[i][j]) cnt++;
        }
    }

    answer = max(cnt, answer);
}

void select(int cur, int depth) {
    if (depth == 3) {
        memset(visited, 0, sizeof(visited));
        bfs();
        return;
    }

    for (int i = cur; i <= n * m; i++) {
        if (isInside((i - 1) / m + 1, (i - 1) % m + 1) && lab[(i - 1) / m + 1][(i - 1) % m + 1] == 0) {
            lab[(i - 1) / m + 1][(i - 1) % m + 1] = 1;
            select(i + 1, depth + 1);
            lab[(i - 1) / m + 1][(i - 1) % m + 1] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            lab[i][j] = c - '0';

            if (lab[i][j] == 2) v.push_back({i, j});
        }
    }

    select(1, 0);

    cout << answer << '\n';

    return 0;
}