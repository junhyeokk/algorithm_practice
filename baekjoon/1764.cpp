#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <iterator>
using namespace std;

int n, m;
set<string> d, b;
vector<string> result;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    while (n--) {
        string tmp;
        cin >> tmp;
        d.insert(tmp);
    }
    while (m--) {
        string tmp;
        cin >> tmp;
        b.insert(tmp);
    }

    set_intersection(d.begin(), d.end(), b.begin(), b.end(), back_inserter(result));

    cout << result.size() << '\n';
    for (string x : result) {
        cout << x << '\n';
    }
    return 0;
}