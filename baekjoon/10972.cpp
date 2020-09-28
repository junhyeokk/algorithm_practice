#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 10001;

int n;
int arr[MAX];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int idx = n - 1;
    for (;idx > 0; idx--) {
        if (arr[idx] > arr[idx - 1]) break;
    }

    if (idx == 0) {
        cout << "-1\n";
        return 0;
    }

    int smallest_idx = idx;
    for (int i = n - 1; i > idx; i--) {
        if (arr[smallest_idx] > arr[i] && arr[i] > arr[idx - 1]) smallest_idx = i;
    }

    swap(arr[idx - 1], arr[smallest_idx]);
    sort(arr + idx, arr + n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';

    return 0;
}