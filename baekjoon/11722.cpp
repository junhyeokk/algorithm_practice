#include <iostream>
using namespace std;

const int MAX = 1001;
int arr[MAX];
int dp[MAX];

int main() {
    int n;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = 1;

        for (int j = 1; j < i; j++) {
            if (arr[i] < arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int ans = -1;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans << '\n';

    return 0;
}