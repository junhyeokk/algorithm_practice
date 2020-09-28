#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> points;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) return a.first < b.first;
    else return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n, mx, curx, cury;
    bool flag;

    cin >> t;
    while (t--) {
        cin >> n;
        points.clear();
        points.resize(n);

        for (int i = 0; i < n; i++) {
            cin >> points[i].first >> points[i].second;
        }

        sort(points.begin(), points.end(), cmp);

        mx = 0;
        flag = true;
        for (auto it = points.begin(); it != points.end(); it++) {
            if (mx < (*it).second) mx = (*it).second;
            else if (mx > (*it).second) {
                flag = false;
                break;
            }
        }

        curx = cury = 0;
        if (flag) {
            cout << "YES\n";
            for (auto it = points.begin(); it != points.end(); it++) {
                for (; curx < (*it).first; curx++) {
                    cout << 'R';
                }

                for (; cury < (*it).second; cury++) {
                    cout << 'U';
                }
            }
        } else {
            cout << "NO";
        }

        cout << '\n';
    }

    return 0;
}