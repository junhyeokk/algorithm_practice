#include <iostream>
using namespace std;

const int MAX = 100001;
int arr[MAX][2];

int main() {
    int n, ans = -1001;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i][0];
    }

    arr[1][1] = -1001;
    for (int i = 2; i <= n; i++) {
        arr[i][1] = max(arr[i - 1][0], arr[i - 1][1] + arr[i][0]);
        arr[i][0] = max(arr[i][0], arr[i - 1][0] + arr[i][0]);
    }

    for (int i = 1; i <= n; i++) {
        ans = max(ans, max(arr[i][0], arr[i][1]));
    }

    cout << ans << '\n';

    return 0;
}