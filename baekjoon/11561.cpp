#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main() {
    int t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;
        ll left = 1LL, right = n;
        ll answer = 1LL;

        while (left <= right) {
            ll mid = (left + right) / 2LL;

            if (mid * (mid + 1LL) / 2LL <= n) {
                // if ()
                answer = max(answer, mid);
                left = mid + 1LL;
            } else {
                right = mid - 1LL;
            }

            // cout << answer << '\n';
        }

        cout << answer << '\n';
    }

    return 0;
}