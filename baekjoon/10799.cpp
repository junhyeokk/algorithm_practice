#include <iostream>
using namespace std;

int main() {
    string s;
    int num = 0, ans = 0;

    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            num++;
        } else if (s[i] == ')') {
            num--;
            if (s[i - 1] == '(') {
                ans += num;
            } else {
                ans++;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}