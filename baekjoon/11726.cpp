#include <iostream>
using namespace std;

int arr[1001] = {0, };

int main() {
    int n;
    int divider = 10007;

    arr[1] = 1;
    arr[2] = 2;

    cin >> n;
    for (int i = 3; i <= n; i++) {
        arr[i] = (arr[i - 2] + arr[i - 1]) % divider;
    }

    cout << arr[n] << '\n';

    return 0;
}