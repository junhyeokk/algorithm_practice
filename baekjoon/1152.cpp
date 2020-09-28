#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int cnt = 0;
    int cur = 0;
    getline(cin, s);
    int cur2 = s.size() - 1;

    while (s[cur] == ' ') cur++;
    while (s[cur2] == ' ') cur2--;

    if (cur == s.size()) {
        cout << 0 << '\n';
        return 0;
    }
    
    for (int i = cur; i <= cur2; i++) {
        if (s[i] == ' ') cnt++;
    }
    cout << cnt + 1 << '\n';
    return 0;
}