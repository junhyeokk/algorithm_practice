#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 9;
int arr[MAX];
int output[MAX];
int n, m;

void solve(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[output[i]] << ' ';
        }
        cout << '\n';
        return;
    }

    int tmp = cnt == 0 ? 0 : output[cnt - 1] + 1;
    for (int i = tmp; i < n; i++) {
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