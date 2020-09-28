#include <iostream>
using namespace std;

const int MAX = 1001;
int arr[MAX][3];
int dp[MAX][3];

int main() {
    int n;
    int answer = 1000010;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    dp[1][0] = 1000010;
    dp[1][1] = arr[1][1]; dp[1][2] = arr[1][2];
    for (int i = 2; i < n; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
    }

    answer = min(answer, min(dp[n - 1][1], dp[n - 1][2]) + arr[n][0]);

    dp[1][1] = 1000010;
    dp[1][0] = arr[1][0]; dp[1][2] = arr[1][2];
    for (int i = 2; i < n; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
    }

    answer = min(answer, min(dp[n - 1][0], dp[n - 1][2]) + arr[n][1]);

    dp[1][2] = 1000010;
    dp[1][0] = arr[1][0]; dp[1][1] = arr[1][1];
    for (int i = 2; i < n; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
    }

    answer = min(answer, min(dp[n - 1][0], dp[n - 1][1]) + arr[n][2]);

    cout << answer << '\n';
    
    return 0;
}