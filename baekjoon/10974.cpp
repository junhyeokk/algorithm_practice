#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
    int n;
    cin >> n;
    v.resize(n);

    for (int i = 0; i < n; i++) {
        v[i] = i + 1;
    }

    do {
        for (int x : v) {
            cout << x << ' ';
        }
        cout << '\n';
    } while (next_permutation(v.begin(), v.end()));

    return 0;
}