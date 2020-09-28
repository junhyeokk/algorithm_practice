#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000001;
int f, s, g, u, d;
int ff[MAX];
bool visited[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> f >> s >> g >> u >> d;
    visited[s] = true;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur + u <= f && !visited[cur + u]) {
            visited[cur + u] = true;
            ff[cur + u] = ff[cur] + 1;
            if (cur + u == g) break;
            q.push(cur + u);
        }
        if (cur - d >= 1 && !visited[cur - d]) {
            visited[cur - d] = true;
            ff[cur - d] = ff[cur] + 1;
            if (cur - d == g) break;
            q.push(cur - d);
        }
    }

    if (!visited[g]) cout << "use the stairs\n";
    else cout << ff[g] << '\n';

    return 0;
}