#include <bits/stdc++.h>
using namespace std;

const int MAX = 10001;
typedef long long ll;
int k, n;
int lans[MAX];

int main() {
    ll left = 1, right = -1;

    cin >> k >> n;
    for (int i = 0; i < k; i++) {
        cin >> lans[i];
        right = max((int)right, lans[i]);
    }

    ll answer = -1;
    while (left <= right) {
        ll mid = (left + right) / 2;

        ll cnt = 0;
        for (int i = 0; i < k; i++) {
            cnt += lans[i] / mid;
        }

        if (cnt >= n) {
            answer = max(answer, mid);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << answer << '\n';

    return 0;
}