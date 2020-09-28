#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, len, cnt;
    bool flag;
    string tmp, result;

    cin >> t;
    while (t--){
        result = "";
        cin >> len;
        cin >> tmp;

        flag = false;
        cnt = 0;
        for (int i = 0; i < len; i++) {
            if ((tmp[i] - '0') % 2 == 0) {
                result += tmp[i];
            } else {
                cnt++;
                result += tmp[i];
                
                if (cnt == 2) flag = true;
            }

            if (flag) break;
        }

        if (flag) cout << result << '\n';
        else cout << "-1\n";
    }

    return 0;
}