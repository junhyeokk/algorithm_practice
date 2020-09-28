#include <bits/stdc++.h>
using namespace std;

bool maze[2][100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    int r, c;
    bool flag;
    int curx, cury;
    memset(maze, 0, sizeof(bool) * 2 * 100001);

    cin >> n >> q;
    while (q--) {
        cin >> r >> c;

        flag = true;
        maze[r - 1][c] = !(maze[r - 1][c]);

        for (int i = 2; i <= n; i++) {
            if ((maze[0][i] && maze[1][i - 1]) || (maze[1][i] && maze[0][i - 1]) || (maze[0][i] && maze[1][i])) {
                flag = false;
                break;
            }
        }

        if (flag) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}