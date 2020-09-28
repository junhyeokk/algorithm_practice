#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 100001;
vector<pair<int, int>> tree[MAX];   // node, distance
bool visited[MAX];
int n;
int sum = 0;
int farest_node;
int longest = -1;

void dfs(int node) {
    visited[node] = true;
    if (longest < sum) {
        longest = sum;
        farest_node = node;
    }

    for (auto x : tree[node]) {
        if (!visited[x.first]) {
            sum += x.second;
            dfs(x.first);
            sum -= x.second;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int cur;
        cin >> cur;

        while(1) {
            int node, dist;
            cin >> node;

            if (node == -1) break;

            cin >> dist;
            tree[cur].push_back({node, dist});
        }
    }

    memset(visited, 0, sizeof(bool) * MAX);
    dfs(1);
    memset(visited, 0, sizeof(bool) * MAX);
    dfs(farest_node);

    cout << longest << '\n';

    return 0;
}