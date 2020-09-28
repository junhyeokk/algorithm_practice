#include <iostream>
using namespace std;

const int MAX = 100001;
int arr[MAX] = {0, };

int main() {
    int n;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        arr[i] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 2; j * j <= i; j++) {
            arr[i] = min(arr[i], arr[i - j * j] + 1);
        }
    }

    cout << arr[n] << '\n';

    return 0;
}