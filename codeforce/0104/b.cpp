#include <bits/stdc++.h>
using namespace std;
const int Max = 100001;

pair<int, int> s[100001];
bool t[100001];

int main() {
    int n, m, tmp;
    int min, max;
    int answer = 0;
    bool isAsc;

    cin >> n;
    for (int i = 0; i < n; i++) {
        min = 1000001;
        max = -1;
        isAsc = false;

        cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> tmp;
            if (min < tmp) isAsc = true;
            if (min > tmp) min = tmp;
            if (max < tmp) max = tmp;
        }

        s[i].first = min;
        s[i].second = max;
        t[i] = isAsc;
    }

    for (int i = 0; i < n; i++) {
        // if (t[i]) {
        //     answer += 2 * n - 1;
        //     continue;
        // }

        for (int j = 0; j < n; j++) {
            if (t[i] || t[j]) {
                answer++;
                continue;
            }

            if (s[i].first < s[j].second) answer++;
        }
    }

    cout << answer;

    return 0;
}