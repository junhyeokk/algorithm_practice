#include <iostream>
using namespace std;

int alpha[26];

int main() {
    string s;
    cin >> s;

    for (char c : s) {
        alpha[c - 'a']++;
    }

    for (int x : alpha) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}