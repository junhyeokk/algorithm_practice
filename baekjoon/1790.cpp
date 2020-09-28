#include <iostream>
using namespace std;

typedef long long ll;

int n, k;

// ll cnt(int n_var) {
//     ll mult = 9;
//     ll return_val = 0;
//     ll cnt = 1;

//     while (n_var > mult) {
//         return_val += mult * cnt;
//         cnt++;
//         mult *= 10;
//     }

//     return return_val + (n_var - mult / 9 + 1) * (cnt);
// }

long long cnt(int x) {
    // 1 ~ 9 : 9 * 1
    // 10 ~ 99 : 90 * 2
    // 100 ~ 999 : 900 * 3
    //     ....
    long long n_length = 0LL;
    long long n_size = to_string(x).size();
    for (long long add = 9LL, len = 1LL; len < n_size; add *= 10, len += 1) {
        n_length += add*len;
    }
    int start = 1;
    // ~ n
    for (int i = 1; i < n_size; i++) {
        start *= 10;
    }
    return n_length += n_size * (x-start+1);
}

int main() {
    cin >> n >> k;

    ll l = cnt(n);
    if (l < k) {
        cout << -1 << '\n';
        return 0;
    }

    int left = 1, right = n;
    int answer, cur;
    while (left <= right) {
        int mid = (left + right) / 2;

        ll len = cnt(mid);

        if (k > len) {
            left = mid + 1;
        } else {
            answer = mid;
            cur = len;
            right = mid - 1;
        }
    }

    string ans = to_string(answer);
    cout << cur << endl;
    cout << ans << endl;
    cout << ans[ans.size() - 1 - (cur - k)] << '\n';

    return 0;
}