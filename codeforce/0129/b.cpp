#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, x;
    string s;

    cin >> t;
    while (t--) {
        int cnt = 0;

        cin >> n >> x;
        cin >> s;

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                cnt++;
            } else {
                cnt--;
            }
        }

        if (x == 0) {
            if (cnt == x) cout << "-1\n";
            else cout << "1\n";
            continue;
        }

        if (cnt == 0) {
            int cnt1 = 0;
            bool flag = false;

            for (int i = 0; i < n; i++) {
                if (s[i] == '0') {
                    cnt1++;
                } else {
                    cnt1--;
                }

                if (cnt1 == x) {
                    flag = true;
                    break;                    
                }
            }

            if (flag) cout << "-1\n";
            else cout << "0\n";

            continue;
        }

        if (cnt == x) {
            cout << "-1\n";
            continue;
        }

        if (x % cnt == 0 && x * cnt >= 0) {
            int cnt1 = 0;
            int ans = 1;

            for (int i = n - 1; i >= 0; i--) {
                if (s[i] == '0') {
                    cnt1++;
                } else {
                    cnt1--;
                }

                if (cnt1 == 0) {
                    ans += 2;                    
                }
            }

            cout << ans << '\n';
        } else {
            cout << "0\n";
        }
    }

    return 0;
}