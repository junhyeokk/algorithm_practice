#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 20001;
vector<int> graph[MAX];
char visited[MAX];
int v, e;
bool flag;

void dfs(int x, char color) {
    if (!flag) return;

    visited[x] = color;
    for (int next : graph[x]) {
        if (!flag) return;

        if (visited[next] == 'a') {
            if (color == 'b') dfs(next, 'c');
            else if (color == 'c') dfs(next, 'b');
        } else if (visited[next] == color) {
            flag = false;
            return;
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> v >> e;
        for (int i = 1; i <= v; i++) {
            graph[i].clear();
        }
        
        for (int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        memset(visited, 'a', sizeof(char) * MAX);
        flag = true;
        for (int i = 1; i <= v; i++) {
            if (visited[i] == 'a') dfs(i, 'b');

            if (!flag) break;
        }

        if (!flag) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}