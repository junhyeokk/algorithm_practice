#include <iostream>
using namespace std;

int main() {
    string s, p;
    cin >> s >> p;

    int cur_p = 0;
    bool flag = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == p[cur_p]) {
            cur_p++;
        } else if (s[i] == p[0]) {
            cur_p = 1;
        } else {
            cur_p = 0;
        }

        if (cur_p == p.size()) {
            flag = true;
            break;
        }
    }

    if (flag) cout << "1\n";
    else cout << "0\n";

    return 0;
}