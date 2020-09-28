#include <iostream>
#include <cmath>
using namespace std;

int n;

void hanoi(int from, int by, int to, int cnt) {
    if (cnt == 1) {
        cout << from << ' ' << to << '\n';
        return;
    }

    hanoi(from, to, by, cnt - 1);
    cout << from << ' ' << to << '\n';
    hanoi(by, from, to, cnt - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin >> n;

    cout << (int)(pow(2, n)) - 1 << '\n';
    hanoi(1, 2, 3, n);
    return 0;
}