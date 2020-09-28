#include <iostream>
using namespace std;

int dp[10001];
int values[101];
int n, k;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> values[i];
        // dp[values[i]] = 1;
    }

    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j - values[i] >= 0) dp[j] += dp[j - values[i]];
        }
    }

    cout << dp[k] << '\n';

    return 0;
}