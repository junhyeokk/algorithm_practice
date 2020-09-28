#include<iostream>
using namespace std;

int coins[11];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, K, idx;
    int cnt = 0;

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }

    idx = N - 1;
    while (K) {
        if (K >= coins[idx]) {
            K -= coins[idx];
            cnt++;
        } else {
            idx--;
        }
    }

    cout << cnt << '\n';
}