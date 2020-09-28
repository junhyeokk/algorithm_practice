#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 501;
int novel[MAX];
int dp[MAX][MAX];

void go(int start, int end) {
    if (dp[start][end] != 2e9) return;

    if (start == end) {
        return;
    }

    if (start + 1 == end) {
        dp[start][end] = novel[end] - novel[start - 1];
        // cout << start << ' ' << end << ' ' << dp[start][end] << endl;
        return;
    }

    for (int i = 0; start + i < end; i++) {
        go(start, start + i);
        go(start + i + 1, end);

        dp[start][end] = min(dp[start][end], dp[start][start + i] + dp[start + i + 1][end]);
    }

    // cout << start << ' ' << end << ' ' << dp[start][end] << endl;
    dp[start][end] += novel[end] - novel[start - 1];
    // cout << start << ' ' << end << ' ' << dp[start][end] << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, k;
    cin >> t;
    while (t--) {
        fill(dp[0], dp[0] + MAX * MAX, 2e9);
        cin >> k;
        for (int i = 1; i <= k; i++) {
            cin >> novel[i];
            dp[i][i] = 0;
            novel[i] += novel[i - 1];
        }

        go(1, k);
        cout << dp[1][k] << '\n';
    }

    return 0;
}