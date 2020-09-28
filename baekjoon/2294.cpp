#include <iostream>
using namespace std;

int dp[10001];
int coins[101];
int n, k;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    fill(dp, dp + 10001, 2e9);

    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j - coins[i] >= 0) dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
    }

    if (dp[k] == 2e9) cout << "-1\n";
    else cout << dp[k] << '\n';

    return 0;
}