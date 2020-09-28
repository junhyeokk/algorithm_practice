#include <iostream>
using namespace std;

const int MAX = 31;

int dp[MAX] = {0, };
int answer[MAX] = {0, };

int main() {
    int n;

    cin >> n;

    dp[0] = 1;
    answer[0] = 1;
    dp[2] = 3;
    for (int i = 4; i <= n; i += 2) {
        dp[i] = 2;
    }

    for (int i = 2; i <= n; i += 2) {
        for (int j = 2; j <= i; j += 2) {
            answer[i] += dp[j] * answer[i - j];
        }
    }

    cout << answer[n] << '\n';

    return 0;
}