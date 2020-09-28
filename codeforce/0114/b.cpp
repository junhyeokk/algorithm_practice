#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    int a, b;
    long long cnt;

    cin >> t;
    while (t--) {
        cnt = 0;
        cin >> a >> b;

        int x = 9;
        while (b >= x) {
            cnt++;

            x *= 10;
            x += 9;
        }

        cout << cnt * a << '\n';
    }

    return 0;
}