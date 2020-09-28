#include <iostream>
using namespace std;

int n;
int arr[12];
int p, m, mul, d;
int small = 2e9, big = -2e9;

void go(int idx, int num) {
    if (idx == n) {
        small = min(small, num);
        big = max(big, num);
        return;
    }

    if (p > 0) {
        p--;
        go(idx + 1, num + arr[idx]);
        p++;
    }
    if (m > 0) {
        m--;
        go(idx + 1, num - arr[idx]);
        m++;
    }
    if (mul > 0) {
        mul--;
        go(idx + 1, num * arr[idx]);
        mul++;
    }
    if (d > 0) {
        d--;
        go(idx + 1, num / arr[idx]);
        d++;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> p >> m >> mul >> d;
    go(1, arr[0]);

    cout << big << '\n';
    cout << small << '\n';

    return 0;
}