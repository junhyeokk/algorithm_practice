#include <iostream>
#include <vector>
using namespace std;

const int MAX = 101;
vector<int> network[MAX];
int n;
bool visited[MAX];

void dfs(int x) {
    visited[x] = true;

    for (int next : network[x]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    int cnt = 0;
    cin >> n;
    int edgeNum;
    cin >> edgeNum;

    for (int i = 0; i < edgeNum; i++) {
        int a, b;
        cin >> a >> b;

        network[a].push_back(b);
        network[b].push_back(a);
    }

    dfs(1);
    for (int i = 1; i <= n; i++) {
        if (visited[i]) cnt++;
    }

    cout << cnt - 1 << '\n';

    return 0;
}