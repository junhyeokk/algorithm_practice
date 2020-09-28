// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     int numbers[100001] = {0,};
//     int dp[100001] = {0,};
//     int t, n;
//     int sum, max;
//     bool flag;
    
//     cin >> t;
//     for (int i = 0; i < t; i++) {
//         sum = 0;
//         max = -1000000001;

//         cin >> n;

//         for (int j = 1; j <= n; j++) {
//             cin >> numbers[j];
//             sum += numbers[j];
//         }

//         for (int j = 1; j < n; j++) {
//             if (dp[j - 1] > 0) {
//                 dp[j] = dp[j - 1] + numbers[j];
//             } else {
//                 dp[j] = numbers[j];
//             }
//         }

//         for (int j = 1; j < n; j++) {
//             if (dp[j] > max) max = dp[j];
//         }

//         dp[0] = 0;
//         dp[1] = 0;

//         for (int j = 2; j <= n; j++) {
//             if (dp[j - 1] > 0) {
//                 dp[j] = dp[j - 1] + numbers[j];
//             } else {
//                 dp[j] = numbers[j];
//             }
//         }

//         for (int j = 2; j <= n; j++) {
//             if (dp[j] > max) max = dp[j];
//         }

//         // cout << sum << ' ' << max << '\n';
//         // cout << flag << '\n';

//         lcm(n, t);

//         if (max >= sum) {
//             cout << "NO" << '\n';
//         } else {
//             cout << "YES" << '\n';
//         }
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
ll a[100000];

ll solve(ll a[100000], int n) {
    ll msf = -1e15, ans = -1e15;

    for (int i = 0; i < n; i++) {
        msf = max(msf, 011) + a[i];
        ans = max(ans, msf);
    }

    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        ll a1 = 0, a2 = solve(a, n - 1);

        for (int i = 0; i < n; i++) {
            a1 += a[i];
        }

        reverse(a, a + n);

        a2 = max(a2, solve(a, n - 1));
        cout << (a1 > a2 ? "YES":"NO") << '\n';
    }
}