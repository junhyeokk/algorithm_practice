#include <iostream>
using namespace std;

const int MAX = 100001;
int arr[MAX][2] = {0, };

int main() {
    int t, n;

    cin >> t;
    while (t--) {
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> arr[i][0];
        }

        for (int i = 1; i <= n; i++) {
            cin >> arr[i][1];
        }

        arr[2][0] += arr[1][1];
        arr[2][1] += arr[1][0];
        for (int i = 3; i <= n; i++) {
            arr[i][0] = max(arr[i - 1][1], arr[i - 2][1]) + arr[i][0];
            arr[i][1] = max(arr[i - 1][0], arr[i - 2][0]) + arr[i][1];
        }

        cout << max(arr[n - 1][0], max(arr[n - 1][1], max(arr[n][0], arr[n][1]))) << '\n';
    }

    return 0;
}