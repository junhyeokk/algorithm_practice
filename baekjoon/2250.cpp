#include <iostream>
using namespace std;

const int MAX = 10001;
int tree[MAX][2];
int low[MAX];
int high[MAX];
int chk[MAX] = {0, };
int deepest_level = -1;
int n;

int dfs(int x, int level, int cur_pos) {
    int cnt = 1;

    if (tree[x][0] != -1)
        cnt += dfs(tree[x][0], level + 1, cur_pos);

    low[level] = min(low[level], cur_pos + cnt);
    high[level] = max(low[level], cur_pos + cnt);

    if (tree[x][1] != -1)
        cnt += dfs(tree[x][1], level + 1, cur_pos + cnt);
    
    deepest_level = max(deepest_level, level);
    return cnt;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (b != -1) chk[b]++;
        if (c != -1) chk[c]++;

        tree[a][0] = b;
        tree[a][1] = c;
    }

    int root;
    for (int i = 1; i <= n; i++) {
        if (chk[i] == 0) {
            root = i;
            break;
        }
    }

    fill(high, high + MAX, -1);
    fill (low, low  + MAX, 1e9);

    dfs(root, 1, 0);

    int answer = -1;
    int answer_level;
    for (int i = 1; i <= deepest_level; i++) {
        if (high[i] - low[i] + 1 > answer) {
            answer = high[i] - low[i] + 1;
            answer_level = i;
        }
    }
    cout << answer_level << ' ' <<  answer << '\n';

    return 0;
}