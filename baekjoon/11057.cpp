#include <iostream>
using namespace std;

// typedef long long ll;

const int MAX = 1001;
const int DIV = 10007;

int arr[MAX][10] = {0, };

int main() {
    int n;
    int ans = 0;

    for (int i = 0; i < 10; i++) {
        arr[1][i] = 1;
    }

    cin >> n;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k <= j; k++) {
                arr[i][j] = (arr[i][j] + arr[i - 1][k]) % DIV;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        ans = (ans + arr[n][i]) % DIV;
    }

    cout << ans << '\n';

    return 0;
}