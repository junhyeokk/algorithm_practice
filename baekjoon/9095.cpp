#include <iostream>
using namespace std;

const int MAX = 12;
int n;
int arr[MAX];

int main() {
    int t;

    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;

    cin >> t;
    while (t--) {
        cin >> n;

        for (int i = 4; i <= n; i++) {
            arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
        }

        cout << arr[n] << '\n';
    }

    return 0;
}