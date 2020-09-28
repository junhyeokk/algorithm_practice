#include <iostream>
using namespace std;

int big = -2e9, small = 2e9;
int n;
int arr[12];
int plus_num, minus_num, mult_num, div_num;

void go(int depth, int val) {
    if (depth == n) {
        big = max(big, val);
        small = min(small, val);
        return;
    }

    if (plus_num > 0) {
        plus_num--;
        go(depth + 1, val + arr[depth]);
        plus_num++;
    }
    if (minus_num > 0) {
        minus_num--;
        go(depth + 1, val - arr[depth]);
        minus_num++;
    }
    if (mult_num > 0) {
        mult_num--;
        go(depth + 1, val * arr[depth]);
        mult_num++;
    }
    if (div_num > 0) {
        div_num--;
        go(depth + 1, val / arr[depth]);
        div_num++;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> plus_num >> minus_num >> mult_num >> div_num;

    go(1, arr[0]);

    cout << big << '\n' << small << '\n';

    return 0;
}