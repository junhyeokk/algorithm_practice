#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;
int m[MAX];
bool visited[MAX];
int n, k;

int main() {
    cin >> n >> k;

    memset(m, 0, sizeof(int) * MAX);
    memset(visited, 0, sizeof(bool) * MAX);

    queue<int> q;
    q.push(n);
    visited[n] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur - 1 >= 0 && !visited[cur - 1]) {
            visited[cur - 1] = true;
            m[cur - 1] = cur;
            q.push(cur - 1);

            if (cur - 1 == k) break;
        }

        if (cur + 1 < MAX && !visited[cur + 1]) {
            visited[cur + 1] = true;
            m[cur + 1] = cur;
            q.push(cur + 1);

            if (cur + 1 == k) break;
        }

        if (cur * 2 < MAX && !visited[2 * cur]) {
            visited[cur * 2] = true;
            m[cur * 2] = cur;
            q.push(2 * cur);

            if (cur * 2 == k) break;
        }
    }

    int cur = k;
    vector<int> ans;
    while (cur != n) {
        ans.push_back(cur);
        cur = m[cur];
    }
    ans.push_back(n);
    
    cout << ans.size() - 1 << '\n';
    for (vector<int>::reverse_iterator it = ans.rbegin(); it != ans.rend(); it++) {
        cout << *it << ' ';
    }
    cout << '\n';

    return 0;
}