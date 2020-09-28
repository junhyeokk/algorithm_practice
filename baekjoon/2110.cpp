#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
int n, c;
vector<int> houses;

int main() {
    ll left = 1, right = -1;

    cin >> n >> c;
    houses.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> houses[i];
        right = max(right, (ll)(houses[i]));
    }

    sort(houses.begin(), houses.end());

    ll answer = -1;
    while (left <= right) {
        ll mid = (right + left) / 2;

        int cnt = 0;
        // cout << mid << ' ';
        for (auto i = houses.begin(); i != houses.end(); i = lower_bound(houses.begin(), houses.end(), *i + mid)) {
            cnt++;
            // cout << *i << ' ';
        }
        // cout << cnt << endl;

        // if (cnt == c) answer = max(answer, mid);

        if (cnt >= c) {
            answer = max(answer, mid);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << answer << '\n';

    return 0;
}