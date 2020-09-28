#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 9;
int n, m;
vector<int> v;
int output[MAX];
int duplicate[10001];

void solve(int depth) {
    if (depth == m) {
        for (int i = 0; i < m; i++) {
            cout << output[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < v.size(); i++) {
        if (duplicate[v[i]]) {
            duplicate[v[i]]--;
            output[depth] = v[i];
            solve(depth + 1);
            duplicate[v[i]]++;
        }
    }
}

int main() {
    memset(duplicate, 0, sizeof(int) * 10001);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        if (duplicate[tmp] == 0) {
            v.push_back(tmp);
            duplicate[tmp]++;
        } else {
            duplicate[tmp]++;
        }
    }

    sort(v.begin(), v.end());
    solve(0);

    return 0;
}