#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 8;
int n, m;
vector<int> v;
int output[MAX];
bool duplicate[10001];

void solve(int depth) {
    if (depth == m) {
        for (int i = 0; i < m; i++) {
            cout << output[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < v.size(); i++) {
        output[depth] = v[i];
        solve(depth + 1);
    }
}

int main() {
    fill(duplicate, duplicate + 10001, false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        if (!duplicate[tmp]) {
            duplicate[tmp] = true;
            v.push_back(tmp);
        }
    }
    sort(v.begin(), v.end());
    solve(0);

    return 0;
}