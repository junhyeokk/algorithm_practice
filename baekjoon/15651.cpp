#include <iostream>
using namespace std;

const int MAX = 8;
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

    for (int i = 1; i <= n; i++) {
        arr[cnt] = i;
        solve(cnt + 1);
    }
}

int main() {
    cin >> n >> m;

    solve(0);

    return 0;
}