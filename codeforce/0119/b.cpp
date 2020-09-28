#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    double ans = 0;

    cin >> n;
    while (n > 0) {
        ans += 1.0 / (double)n;
        n--;
    }

    cout << ans << '\n';

    return 0;
}