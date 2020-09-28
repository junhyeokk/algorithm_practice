#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(char a, char b) {
    return a > b;
}

int main() {
    string s;
    long long sum = 0;
    long long zeros = 0;

    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            zeros++;
            // s[i] = 'a';
        } else {
            sum += s[i] - '0';
        }
    }

    if (zeros && sum % 3 == 0) {
        // for (int i = 0; i < s.size(); i++) {
        //     if (s[i] == 'a') continue;
        //     else cout << s[i];
        // }

        // for (int i = 0; i < zeros; i++) {
        //     cout << '0';
        // }
        
        sort(s.begin(), s.end(), cmp);

        cout << s;
    } else {
        cout << "-1";
    }

    cout << '\n';

    return 0;
}