#include <iostream>
using namespace std;

const int MAX = 501;
int arr[MAX][MAX];

int main() {
    int n;
    int ans = -1;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1) {
                arr[i][j] += arr[i - 1][j];
            } else if (j == i) {
                arr[i][j] += arr[i - 1][j - 1];
            } else {
                arr[i][j] += max(arr[i - 1][j - 1], arr[i - 1][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        ans = max(ans, arr[n][i]);
    }

    cout << ans << '\n';
    return 0;
}