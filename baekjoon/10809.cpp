#include <iostream>
#include <cstring>
using namespace std;

int alpha[26];

int main() {
    string s;

    memset(alpha, -1, 26 * sizeof(int));

    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (alpha[s[i] - 'a'] == -1) {
            alpha[s[i] - 'a'] = i;
        }
    }

    for (int i : alpha) {
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}