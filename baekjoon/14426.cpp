#include <iostream>
#include <set>
using namespace std;

int n, m;
set<string> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cnt = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;

        for (int j = 1; j <= tmp.size(); j++) {
            s.insert(tmp.substr(0, j));
            cout << tmp.substr(0, j) << endl;
        }
    }

    for (int i = 0; i < m; i++) {
        string tmp;
        cin >> tmp;
        if (s.find(tmp) != s.end()) cnt++;
    }

    cout << cnt << '\n';

    return 0;
}