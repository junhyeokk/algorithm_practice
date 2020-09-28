#include <iostream>
using namespace std;

const int MAX = 1500101;
int n;
int consult[MAX][2];
int dp[MAX] = {0, };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int so_far = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> consult[i][0] >> consult[i][1];
    }

    for (int i = 0; i < n; i++) {
        so_far = max(so_far, dp[i]);
        dp[i + consult[i][0]] = max(so_far + consult[i][1], dp[i + consult[i][0]]);
    }

    int answer = 0;
    for (int i = 0; i <= n; i++) {
        // cout << dp[i] << endl;
        answer = max(answer, dp[i]);
    }
    cout << answer << '\n';

    return 0;
}