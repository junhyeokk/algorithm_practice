#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;

    if (s.size() % 3 == 1) {
        s = "00" + s;
    } else if (s.size() % 3 == 2) {
        s = "0" + s;
    }

    // for (int i = s.size() - 1; i >= 2; i -= 3) {
    //     output = (char)(s[i] - '0' + (s[i - 1] - '0') * 2 + (s[i - 2] - '0') * 4 + '0') + output;
    // }
    for (int i = 0; i < s.size(); i += 3) {
        cout << (s[i] - '0') * 4 + (s[i + 1] - '0') * 2 + s[i + 2] - '0';
    }

    cout << '\n';

    return 0;
}