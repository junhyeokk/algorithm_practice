#include <iostream>
using namespace std;

typedef long long ll;

const int MOD = 1000000000;

const int MAX = 101;
ll arr[MAX][10] = {0};

int main() {
    int n;
    cin >> n;

    for (int i = 1; i < 10; i++) {
        arr[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        arr[i][0] = arr[i - 1][1];

        for (int j = 1; j < 9; j++) {
            arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1]) % MOD;
        }

        arr[i][9] = arr[i - 1][8];
    }

    ll ans = 0;
    for (int i = 0; i < 10; i++) {
        ans = (ans + arr[n][i]) % MOD;
    }
    cout << ans << '\n';

    return 0;
}