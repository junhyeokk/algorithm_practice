#include <bits/stdc++.h>
using namespace std;

string s[21];
string t[21];

int main() {
    int n1, n2, n, year, x, y;

    cin >> n1;
    cin >> n2;

    for (int i = 0; i < n1; i++) {
        cin >> s[i];
    }

    for (int i = 0; i < n2; i++) {
        cin >> t[i];
    }

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> year;

        year--;
        x = year % n1;
        y = year % n2;

        cout << s[x] << t[y] << '\n';
    }

    return 0;
}
