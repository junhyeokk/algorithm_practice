#include <iostream>
using namespace std;

typedef long long ll;

int gcd(int a, int b) {
    int tmp;

    while (a % b) {
        tmp = b;
        b = a % b;
        a = tmp;
    }

    return b;
}

ll lcd(int a, int b) {
    if (a > b) {
        return a * b / gcd(a, b);
    } else {
        return a * b / gcd(b, a);
    }
}

ll solve(int m, int n, int x, int y) {
    ll mx = lcd(m, n);

    for (ll i = x; i <= mx; i += m) {
        if ((i - y) % n == 0) return i;
    }

    return -1;
}

int main() {
    int t;
    int m, n, x, y;

    cin >> t;
    while (t--) {
        cin >> m >> n >> x >> y;

        cout << solve(m, n, x, y) << '\n';
    }

    return 0;
}