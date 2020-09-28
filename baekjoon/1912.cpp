#include <iostream>
using namespace std;

const int MAX = 100001;

int arr[MAX];

int main() {
    int n;
    int ans = -1000;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        if (arr[i - 1] + arr[i] > arr[i]) arr[i] = arr[i - 1] + arr[i];

        ans = max(ans, arr[i]);
    }

    cout << ans << '\n';

    return 0;
}