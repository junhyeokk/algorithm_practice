#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 9;
int n, m;
bool duplicate[10001];
vector<int> v;
int output[MAX];

void solve(int depth) {
    if (depth == m) {
        for (int i = 0; i < m; i++) {
            cout << output[i] << ' ';
        }
        cout << '\n';
        return;
    }

    int tmp = depth == 0 ? 0 : output[depth - 1];
    for (int i = 0; i < v.size(); i++) {
        if (tmp <= v[i]) {
            output[depth] = v[i];
            solve(depth + 1);
        }
    }
}

int main() {
    cin >> n >> m;
    fill (duplicate, duplicate + 10001, false);

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