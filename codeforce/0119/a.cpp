#include <bits/stdc++.h>
using namespace std;

set <int, greater<int>> closed_res;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n, s, k;
    int tmp, cand1, cand2;
    int cnt;

    cin >> t;
    while (t--) {
        closed_res.clear();
        cin >> n >> s >> k;

        cand1 = cand2 = s;
        cnt = 0;
        while (k--) {
            cin >> tmp;

            closed_res.insert(tmp);
        }

        while (1) {
            if (closed_res.find(cand1) == closed_res.end() || closed_res.find(cand2) == closed_res.end()) break;

            if (cand1 > 1) cand1--;
            if (cand2 < n) cand2++;
            cnt++;
        }

        cout << cnt << '\n';
    }


    return 0;
}