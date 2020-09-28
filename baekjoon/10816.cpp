#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    cin >> m;
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;

        cout << upper_bound(v.begin(), v.end(), tmp) - lower_bound(v.begin(), v.end(), tmp) << ' ';
    }
    cout << '\n';

    return 0;
}