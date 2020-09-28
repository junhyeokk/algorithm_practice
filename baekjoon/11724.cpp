#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1001;
int n, m;
vector<int> graph[MAX];
bool visited[MAX];

void dfs(int x) {
    visited[x] = true;

    for (int next : graph[x]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    int comp_num = 0;

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            comp_num++;
            dfs(i);
        }
    }

    cout << comp_num << '\n';

    return 0;
}