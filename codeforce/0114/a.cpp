#include <bits/stdc++.h>
using namespace std;

int ceil1(double a) {
    return (int)(a + 0.5);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    int n, d;

    cin >> t;
    while (t--) {
        cin >> n >> d;

        if (n >= d) {
            cout << "YES\n";
            continue;
        }

        bool flag = false;
        for (int i = 1; i < n; i++) {
            if (i + ceil((double)d / (double)(i + 1)) <= n) {
                flag = true;
                break;
            }
        }

        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }


    return 0;
}