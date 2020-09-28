#include <iostream>
#include <set>
#include <queue>
using namespace std;

const int MAX = 100001;
set<int> graph[MAX];
int n, cur;
int cand[MAX];

int bfs() {
    queue<int> q;

    q.push(1);
    cur = 1;
    while (!q.empty()) {
        int x = q.front(); q.pop();

        for (int i = 0; i < graph[x].size() - 1; i++) {
            if (graph[x].count(cand[cur])) {
                q.push(cand[cur]);
                cur++;
            } else {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].insert(b);
        graph[b].insert(a);
    }
    graph[1].insert(1);

    for (int i = 0; i < n; i++) {
        cin >> cand[i];
    }

    if (cand[0] != 1) {
        cout << "0\n";
        return 0;
    }

    cout << bfs() << '\n';

    return 0;
}