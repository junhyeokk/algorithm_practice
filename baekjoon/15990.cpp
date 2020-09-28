#include <iostream>
using namespace std;

typedef long long ll;

const int MAX = 100001;
const int DIV = 1000000009;

ll arr[MAX][4] = {0, };

int main() {
    int t, n;

    arr[1][1] = 1;
    arr[2][2] = 1;
    arr[3][1] = 1;
    arr[3][2] = 1;
    arr[3][3] = 1;
    for (int i = 4; i <= MAX; i++) {
        arr[i][1] = (arr[i - 1][2] + arr[i - 1][3]) % DIV;
        arr[i][2] = (arr[i - 2][1] + arr[i - 2][3]) % DIV;
        arr[i][3] = (arr[i - 3][1] + arr[i - 3][2]) % DIV;
    }

    cin >> t;
    while (t--) {
        cin >> n;

        ll sum = (arr[n][1] + arr[n][2] + arr[n][3]) % DIV; 
        cout << sum << '\n';
    }

    return 0;
}