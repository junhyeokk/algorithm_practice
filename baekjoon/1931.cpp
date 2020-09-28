#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100001;
int n;
int cnt = 1;
pair<int, int> meetings[MAX];

int cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> meetings[i].first >> meetings[i].second;
    }
    sort(meetings, meetings + n, cmp);

    int cur_time = meetings[0].second;
    for (int i = 1; i < n; i++) {
        if (cur_time <= meetings[i].first) {
            cnt++;
            cur_time = meetings[i].second;
        }
    }
    cout << cnt << '\n';

    return 0;
}