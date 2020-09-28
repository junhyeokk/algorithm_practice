#include <iostream>
#include <vector>
using namespace std;

const int MAX = 16;
// bool chess[MAX][MAX] = {0, };
int n;
vector<pair<int, int>> cand;
int cnt = 0;

bool go(int depth, int pos) {
    if (depth == n + 1) {
        cnt++;
        // for (auto p : cand) {
        //     cout << p.first << ' ' << p.second << '\n';
        // }
        // cout << endl;
        return true;
    }

    for (int i = 0; i < cand.size(); i++) {
        if (cand[i].second == pos) {
            return false;
        }

        if (abs(cand[i].first - depth) == abs(cand[i].second - pos)) {
            return false;
        }
    }
    cand.push_back({depth, pos});

    for (int i = 1; i <= n; i++) {
        if (go(depth + 1, i)) break;
    }
    cand.pop_back();
    return false;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        go(1, i);
    }
    cout << cnt << '\n';

    return 0;
}