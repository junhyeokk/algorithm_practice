#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 10001;

int main() {
    int n;
    vector<int> v;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    if (next_permutation(v.begin(), v.end())) {
        for (int x : v) {
            cout << x << ' ';
        }
        cout << '\n';
    } else {
        cout << "-1\n";
    }

    return 0;
}