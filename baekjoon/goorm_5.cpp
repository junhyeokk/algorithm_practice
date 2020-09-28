#include <bits/stdc++.h>
using namespace std;

const int MAX = 10001;
int n;
vector<pair<int, int>> graph[MAX];  //node, dist
bool visited[MAX];
int total = 0;

int dfs(int node) {
    visited[node] = true;

    int node_cnt = 0;
    for (auto x : graph[node]) {
        if (!visited[x.first]) {
            int child_cnt = dfs(x.first);
            node_cnt += child_cnt;
            total += x.second * child_cnt;
        }
    }
    return node_cnt + 1;
}

int main() {
    int answer = 1000010;

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b, dist;
        cin >> a >> b >> dist;
        graph[a].push_back({b, dist});
        graph[b].push_back({a, dist});
    }

    for (int i = 0; i < n; i++) {
        memset(visited, 0, sizeof(bool) * MAX);
        total = 0;
        dfs(i);
        answer = min(answer, total);
    }
    cout << answer << '\n';

    return 0;
}