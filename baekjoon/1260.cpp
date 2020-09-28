#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 1001;
int n, m, v;
vector<int> graph[MAX];
bool visited[MAX];
queue<int> q;

void dfs(int x) {
    visited[x] = true;
    cout << x << ' ';

    for (int next : graph[x]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}

void bfs(int x) {
    q.push(x);
    visited[x] = true;

    while (!q.empty()) {
        int a = q.front();
        q.pop();

        cout << a << ' ';
        for (int next : graph[a]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    memset(visited, 0, sizeof(bool) * MAX);
    dfs(v);
    cout << '\n';

    memset(visited, 0, sizeof(bool) * MAX);
    bfs(v);
    cout << '\n';

    return 0;
}