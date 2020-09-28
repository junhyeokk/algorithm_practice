#include <iostream>
#include <set>
using namespace std;

int n;
set<string> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    while (n--) {
        string name, log;
        cin >> name >> log;

        if (log == "enter") {
            s.insert(name);
        } else {
            s.erase(name);
        }
    }

    for (auto it = s.rbegin(); it != s.rend(); it++) {
        cout << *it << '\n';
    }

    return 0;
}