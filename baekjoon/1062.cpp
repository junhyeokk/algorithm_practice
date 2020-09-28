#include <bits/stdc++.h>
using namespace std;

int n, k;
string arr[51];
bool visited[26];
int answer = 0;

void go(char cur, int depth) {
    if (depth == k - 5) {
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            bool flag = true;

            for (char c : arr[i]) {
                if (!visited[c - 'a']) {
                    flag = false;
                    break;
                }
            }

            if (flag) cnt++;
        }

        answer = max(answer, cnt);
        return;
    }

    for (char c = cur; c <= 'z'; c++) {
        if (!visited[c - 'a']) {
            visited[c - 'a'] = true;
            go(c, depth + 1);
            visited[c - 'a'] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (k < 5) {
        cout << "0\n";
        return 0;
    }

    visited['a' - 'a'] = true;
    visited['n' - 'a'] = true;
    visited['t' - 'a'] = true;
    visited['i' - 'a'] = true;
    visited['c' - 'a'] = true;

    go('a', 0);
    cout << answer << '\n';

    return 0;
}