#include <iostream>
using namespace std;

int n, s, m;
bool dp[101][1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s >> m;
    dp[0][s] = true;

    int diff;
    for (int i = 1; i <= n; i++) {
        cin >> diff;

        for (int j = 0; j <= m; j++) {
            if (dp[i - 1][j]) {
                if (j + diff <= m) {
                    dp[i][j + diff] = true;
                }

                if (j - diff >= 0) {
                    dp[i][j - diff] = true;
                }
            }
        }
    }

    int answer = -1;
    for (int i = m; i >= 0; i--) {
        if (dp[n][i]) {
            answer = i;
            break;
        }
    }
    cout << answer << '\n';

    return 0;
}