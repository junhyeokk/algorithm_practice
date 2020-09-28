#include <iostream>
using namespace std;

const int MAX = 1001;

int arr[MAX][3] = {0, };

int main() {
    int n;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

        arr[i][0] = min(arr[i - 1][1], arr[i - 1][2]) + arr[i][0];
        arr[i][1] = min(arr[i - 1][0], arr[i - 1][2]) + arr[i][1];
        arr[i][2] = min(arr[i - 1][0], arr[i - 1][1]) + arr[i][2];
    }

    cout << min(arr[n][0], min(arr[n][1], arr[n][2])) << '\n';

    return 0;
}