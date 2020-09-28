#include <iostream>
using namespace std;

typedef long long ll;
const int DIV = 1000000007;
ll arr[5001][2];
// 0은 중복
// 1은 앞에 괄호에서 양 끝을 괄호로 감싼 것

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n;
    int cur = 4;

    cin >> t;
    arr[2][0] = 1;
    arr[2][1] = 1;
    while (t--) {
        cin >> n;
        if (n % 2 == 1) {
            cout << 0 << '\n';
            continue;
        }

        for (int i = cur; i <= n; i += 2) {
            arr[i][1] = arr[i - 2][0];
            for (int j = 2; j < i; j += 2) {
                arr[i][0] += (arr[j][1] * arr[i - j][0]) % DIV;
                arr[i][0] = arr[i][0] % DIV;
            }
            arr[i][0] = (arr[i][0] + arr[i][1]) % DIV;
        }
        cur = n + 2;

        cout << arr[n][0] << '\n';
    }

    return 0;
}