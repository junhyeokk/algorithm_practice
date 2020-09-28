#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1001;
int n;
int maze[MAX], dp[MAX];

int main() {
    cin >> n;

    fill(&(dp[0]), &(dp[MAX]), 1e9);
    dp[0] = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> maze[i];

        int reachable = i + maze[i];
        if (reachable > n - 1) reachable = n - 1;

        for (int j = i + 1; j <= reachable; j++) {
            dp[j] = min(dp[j], dp[i] + 1);
        } 
    }

    if (dp[n - 1] == 1e9) cout << "-1\n";
    else cout << dp[n - 1] << '\n';

    return 0;
}