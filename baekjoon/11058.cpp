#include <bits/stdc++.h>
using namespace std;

const int MAX = 101;
long long arr[MAX];
int n;

int main() {
    cin >> n;

    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    arr[4] = 4;
    arr[5] = 5;
    arr[6] = 6;
    for (int i = 7; i <= n; i++) {
        arr[i] = arr[i - 1] + 1;
        for (int j = 1; j <= i - 3; j++) {
            arr[i] = max(arr[i], arr[j] * (i - j - 1));
        }
    }

    cout << arr[n] << '\n';

    return 0;
}