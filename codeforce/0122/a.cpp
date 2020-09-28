#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n;
    int arr[3];

    cin >> t;
    while (t--) {
        cin >> arr[0] >> arr[1] >> arr[2] >> n;
        sort(arr, arr + 3);

        n -= arr[2] - arr[0];
        n -= arr[2] - arr[1];

        if (n < 0) {
            cout << "NO\n";
        } else if (n % 3 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}