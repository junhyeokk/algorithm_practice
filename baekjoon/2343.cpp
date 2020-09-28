#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 100001;
int n, m;
int lessons[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll left = 0, right = 0;
    int answer = 2e9;
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> lessons[i];
        right += lessons[i];
        left = max(left, (ll)lessons[i]);
    }

    while (left <= right) {
        ll mid = (left + right) / 2;

        int cnt = 1;
        ll sum = lessons[0];
        for (int i = 1; i < n; i++) {
            if (sum + lessons[i] <= mid) {
                sum += lessons[i];
            } else {
                sum = lessons[i];
                cnt++;
            }
        }

        if (cnt <= m) {
            // cout << mid << ' ' << cnt << '\n';
            right = mid - 1;
            answer = (int)min((ll)answer, mid);
        } else {
            left = mid + 1;
        }
    }

    cout << answer << '\n';

    return 0;
}