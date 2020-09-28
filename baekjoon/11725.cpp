#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 100001;
vector<int> graph[MAX];
int n;
int answer[MAX];
bool visited[MAX];

void dfs(int node) {
    visited[node] = true;

    for (int x : graph[node]) {
        if (!visited[x]) {
            answer[x] = node;
            dfs(x);
        }
    }
}

int main() {
    memset(visited, 0, sizeof(bool) * MAX);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1);

    for (int i = 2; i <= n; i++) {
        cout << answer[i] << '\n';
    }

    return 0;
}