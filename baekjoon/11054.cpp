#include <iostream>
using namespace std;

const int MAX = 1001;

int arr[MAX];
int dp1[MAX];
int dp2[MAX];

int main() {
    int n;
    int ans = -1;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        dp1[i] = 1;

        for (int j = 1; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp1[i] = max(dp1[j] + 1, dp1[i]);
            }
        }
    }

    for (int i = n; i >= 1; i--) {
        dp2[i] = 1;

        for (int j = n; j > i; j--) {
            if (arr[j] < arr[i]) {
                dp2[i] = max(dp2[j] + 1, dp2[i]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp1[i] + dp2[i] - 1);
    }

    cout << ans << '\n';

    return 0;
}