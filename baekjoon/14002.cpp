#include <iostream>
using namespace std;

int input[1001];
int dp[1001];
int index[1001];

int main() {
    int n;
    int ans = 1, ans_idx = 1;
    int output[1001];

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> input[i];
        dp[i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        int prev_idx = 0;

        for (int j = 1; j < i; j++) {
            if (input[i] > input[j]) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev_idx = j;
                }
            }
        }

        index[i] = prev_idx;
        if (ans < dp[i]) {
            ans = dp[i];
            ans_idx = i;
        }
    }

    int a = ans_idx;
    for (int i = ans; i > 0; i--) {
        output[i] = input[a];
        a = index[a];
    }

    cout << ans << '\n';
    for (int i = 1; i <= ans; i++) {
        cout << output[i];

        if (i != ans) cout << " ";
    }
    cout << '\n';

    return 0;
}