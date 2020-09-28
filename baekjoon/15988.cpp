#include <iostream>
using namespace std;

const int MAX = 1000001;
const int DIV = 1000000009;

typedef long long ll;

ll arr[MAX] = {0, };

int main() {
    int t, n;

    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;

    for (int i = 4; i < MAX; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2] + arr[i - 3]) % DIV;
    }

    cin >> t;
    while (t--) {
        cin >> n;

        cout << arr[n] << '\n';
    }

    return 0;
}