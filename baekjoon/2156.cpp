#include <iostream>
using namespace std;

const int MAX = 10001;
int arr[MAX];
int dp[MAX] = {0, };

int main() {
    int n;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    dp[3] = max(arr[1], arr[2]) + arr[3];

    for (int i = 4; i <= n; i++) {
        dp[i] = arr[i] + max(max(dp[i - 3] + arr[i - 1], dp[i - 2]), dp[i - 4] + arr[i - 1]);
    }

    cout << max(dp[n], dp[n - 1]) << '\n';
    return 0;
}