#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000001;
typedef long long ll;
int n, m;
int trees[MAX];

int main() {
    ll left = 0, right = -1;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> trees[i];
        right = max((ll)trees[i], right);
    }

    ll answer = -1;
    while (left <= right) {
        ll mid = (left + right) / 2;

        ll sum = 0;
        for (int i = 0; i < n; i++) {
            if (trees[i] - mid > 0) {
                sum += trees[i] - mid;
            }
        }

        if (sum >= m) {
            answer = max(answer, mid);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << answer << '\n';

    return 0;
}