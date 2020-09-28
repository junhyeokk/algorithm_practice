#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int euclid(int a, int b) {
    int x;

    while (a % b) {
        x = a % b;
        a = b;
        b = x;
    }

    return b;
}

int main() {
    int n;
    int ans = -1;

    cin >> n >> arr[0];
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n + 1);

    for (int i = 0; i < n; i++) {
        arr[i] = arr[i + 1] - arr[i];
    }

    ans = arr[0];

    for (int i = 1; i < n; i++) {
        if (ans > arr[i]) {
            ans = euclid(ans, arr[i]);
        } else {
            ans = euclid(arr[i], ans);
        }
    }

    cout << ans << '\n';
    return 0;
}