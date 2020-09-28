#include <iostream>
using namespace std;

const int MAX = 201;
const int DIV = 1000000000;

typedef long long ll;

int arr[MAX][MAX] = {0, };

int main() {
    int n, k;

    cin >> n >> k;

    for (int i = 0; i <= n; i++) {
        arr[1][i] = 1;
    }

    for (int i = 0; i <= k; i++) {
        arr[i][0] = 1;
    }

    for (int i = 2; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            arr[i][j] = ((ll)(arr[i - 1][j]) + (ll)(arr[i][j - 1])) % DIV;
        }
    }

    cout << arr[k][n] << '\n';

    return 0;
}