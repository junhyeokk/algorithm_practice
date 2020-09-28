#include <iostream>
using namespace std;

const int MAX = 9;
int n, m;
int arr[MAX];

void solve(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < cnt; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    int tmp = cnt == 0 ? 1 : arr[cnt - 1];
    for (int i = tmp; i <= n; i++) {
        arr[cnt] = i;
        solve(cnt + 1);
    }
}

int main() {
    cin >> n >> m;

    solve(0);

    return 0;
}