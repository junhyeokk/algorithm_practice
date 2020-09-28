#include <iostream>
using namespace std;

int arr[1001] = {0, };

int main() {
    int n;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            arr[i] = min(arr[i], arr[j] + arr[i - j]);
        }
    }

    cout << arr[n] << '\n';

    return 0;
}