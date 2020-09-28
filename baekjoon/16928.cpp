#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 101;
int n, m;
int shortcut[MAX] = {0, };
int cnt[MAX];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n + m; i++) {
        int a, b;
        cin >> a >> b;
        shortcut[a] = b;
    }

    fill(cnt, cnt + MAX, 1e9);
    queue<int> q;
    q.push(1);
    cnt[1] = 0;

    while (!q.empty()) {
        int pos = q.front();
        q.pop();

        for (int i = 1; i <= 6; i++) {
            if (pos + i > 100) continue;

            int next;
            if (shortcut[pos + i] == 0) next = pos + i;
            else next = shortcut[pos + i];

            if (cnt[next] > cnt[pos] + 1) {
                cnt[next] = cnt[pos] + 1;
                q.push(next);
            }
        }
    }

    cout << cnt[100] << '\n';

    return 0;
}