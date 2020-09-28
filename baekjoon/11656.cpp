#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<string> v;
    string s;

    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        v.push_back(s.substr(i, s.size() - i));
    }

    sort(v.begin(), v.end());

    for (string x : v) {
        cout << x << '\n';
    }

    return 0;
}