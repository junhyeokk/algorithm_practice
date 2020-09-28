#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 2000001;
int n;
int arr[21];
bool chk[MAX];

void go(int idx, int num) {
    if (idx == n) {
        chk[num] = true;
        return;
    }

    go(idx + 1, num + arr[idx]);
    go(idx + 1, num);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    memset(chk, 0, sizeof(bool) * MAX);
    go(0, 0);

    for (int i = 1; i < MAX; i++) {
        if (!chk[i]) {
            cout << i << '\n';
            break;
        }
    }

    return 0;
}