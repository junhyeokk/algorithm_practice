#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 2001;
int n, m;
vector<int> graph[MAX];
int visited[MAX];

void dfs(int x, int depth) {
    if (depth == 4) {
        cout << "1\n";
        exit(0);
    }

    visited[x] = true;
    for (int next : graph[x]) {
        if (!visited[next]) {
            dfs(next, depth + 1);
        }
    }
    visited[x] = false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(bool) * MAX);
        dfs(i, 0);
    }
    cout << "0\n";

    return 0;
}