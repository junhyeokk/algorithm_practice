#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 8;
int n, m;
int arr[MAX];
int output[MAX];

void solve(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < cnt; i++) {
            cout << arr[output[i]] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        output[cnt] = i;

        solve(cnt + 1);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    solve(0);

    return 0;
}