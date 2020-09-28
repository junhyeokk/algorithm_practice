#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;
int values[101][MAX];
int n, k;
pair<int, int> arr[101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
        // values[1][arr[i].first] = arr[i].second;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            values[i][j] = max(values[i - 1][j], values[i][j]);
            if (j - arr[i - 1].first >= 0) values[i][j] = max(values[i][j], values[i - 1][j - arr[i - 1].first] + arr[i - 1].second);
        }
    }
    
    cout << values[n][k] << '\n';
    return 0;
}