#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
int n;
vector<ll> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll answer_num;
    int cnt, cur_cnt;

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    
    answer_num = v[0];
    cnt = 1;
    cur_cnt = 1;
    for (int i = 1; i < v.size(); i++) {
        if (v[i - 1] == v[i]) cur_cnt++;
        else cur_cnt = 1;

        if (cur_cnt > cnt) {
            cnt = cur_cnt;
            answer_num = v[i];
        }
    }

    cout << answer_num << '\n';

    return 0;
}