#include <iostream>
using namespace std;

typedef long long ll;
int n;
ll arr[101][21];
int inpt[101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> inpt[i];
    }

    arr[0][inpt[0]] = 1;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 0; j < 21; j++) {
            if (j + inpt[i] <= 20) {
                arr[i][j + inpt[i]] += arr[i - 1][j];
            }

            if (j - inpt[i] >= 0) {
                arr[i][j - inpt[i]] += arr[i - 1][j];
            }
        }
    }

    cout << arr[n - 2][inpt[n - 1]] << '\n';

    return 0;
}