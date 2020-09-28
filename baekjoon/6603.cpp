#include <iostream>
#include <cstring>
using namespace std;

int arr[13];
int output[6];
int k;
bool chk[13];

void solve(int depth) {
    if (depth == 6) {
        for (int x : output) cout << x << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < k; i++) {
        if (!chk[i] && (depth == 0 || arr[i] > output[depth - 1])) {
            output[depth] = arr[i];

            chk[i] = true;
            solve(depth + 1);
            chk[i] = false;
        }
    }
}

int main() {
    cin >> k;

    while (k != 0) {
        memset(chk, 0, sizeof(bool) * 13);

        for (int i = 0; i < k; i++) {
            cin >> arr[i];
        }

        solve(0);
        
        cout << '\n';
        cin >> k;
    }

    return 0;
}