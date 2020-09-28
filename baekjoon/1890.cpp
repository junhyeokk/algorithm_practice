#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 111;
int n;
int board[MAX][MAX];
ll dp[MAX][MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
            if (i == n && j == n) continue;
            dp[i + board[i][j]][j] += dp[i][j];
            dp[i][j + board[i][j]] += dp[i][j];
        }
    }

    cout << dp[n][n] << '\n';

    return 0;
}