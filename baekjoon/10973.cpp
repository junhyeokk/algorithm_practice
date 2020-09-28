#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 10001;
int arr[MAX];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int idx = n - 1;
    for (; idx > 0; idx--) {
        if (arr[idx] < arr[idx - 1]) break;
    }

    if (idx == 0) {
        cout << "-1\n";
        return 0;
    }

    int biggest_idx = idx;
    for (int i = idx; i < n; i++) {
        if (arr[biggest_idx] < arr[i] && arr[idx - 1] > arr[i]) biggest_idx = i;
    }

    swap(arr[idx - 1], arr[biggest_idx]);
    sort(arr + idx, arr + n, cmp);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';

    return 0;
}