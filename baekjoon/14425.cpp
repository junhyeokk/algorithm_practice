#include <iostream>
#include <set>
using namespace std;

int n, m;
set<string> s;

int main() {
    int cnt = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        s.insert(tmp);
    }

    for (int i = 0; i < m; i++) {
        string tmp;
        cin >> tmp;
        if (s.count(tmp) != 0) cnt++;
    }

    cout << cnt << '\n';

    return 0;
}