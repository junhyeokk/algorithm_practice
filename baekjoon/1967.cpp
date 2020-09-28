#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 10001;
int n;
vector<pair<int, int>> graph[MAX];  // node, distance
bool visited[MAX];
int farest = -1;
int farest_node;
int sum = 0;

void dfs(int node) {
    visited[node] = true;
    if (sum > farest) {
        farest = sum;
        farest_node = node;
    }

    for (auto x : graph[node]) {
        if (!visited[x.first]) {
            sum += x.second;
            dfs(x.first);
            sum -= x.second;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b, dist;
        cin >> a >> b >> dist;

        graph[a].push_back({b, dist});
        graph[b].push_back({a, dist});
    }

    memset(visited, 0, sizeof(bool) * MAX);
    dfs(1);
    memset(visited, 0, sizeof(bool) * MAX);
    dfs(farest_node);

    cout << farest << '\n';

    return 0;
}