#include <iostream>
using namespace std;

const int MAX = 1000001;
int arr[MAX] = {0, };

int main() {
    int n;
    cin >> n;

    arr[0] = arr[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (i % 3 == 0 && i % 2 == 0) {
            arr[i] = min(arr[i / 3], min(arr[i / 2], arr[i - 1])) + 1;
        } else if (i % 2 == 0) {
            arr[i] = min(arr[i / 2], arr[i - 1]) + 1;
        } else if (i % 3 == 0) {
            arr[i] = min(arr[i / 3], arr[i - 1]) + 1;
        } else {
            arr[i] = arr[i - 1] + 1;
        }
    }

    cout << arr[n] << '\n';

    return 0;
}