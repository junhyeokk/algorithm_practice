#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n;
    int a, b, c;

    cin >> t;
    while (t--) {
        cin >> n;

        a = b = c = 0;
        for (int i = 2; n != 1; i++) {
            if (n % i == 0) {
                if (a == 0) {
                    a = i;
                } else if (b == 0) {
                    b = i;
                    c = n / i;
                    break;
                }

                n = n / i;
            }
        }

        if (a != 0 && b != 0 && c != 0 && a != b && a != c && b != c) cout << "YES\n" << a << ' ' << b << ' ' << c << '\n';
        else cout << "NO\n";
    }

    return 0;
}