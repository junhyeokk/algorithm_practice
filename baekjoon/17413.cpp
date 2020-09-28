#include <iostream>
using namespace std;

char buf[100001];

int main() {
    bool inTag = false;
    string s;
    int bufidx = 0;

    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '<') inTag = true;
        else if (s[i] == '>') {
            inTag = false;
            cout << '>';
            continue;
        }

        if (inTag) {
            if (bufidx != 0) {
                for (int j = bufidx - 1; j >= 0; j--) {
                    cout << buf[j];
                }

                bufidx = 0;
            }
            cout << s[i];
        } else {
            if (s[i] == ' ') {
                for (int j = bufidx - 1; j >= 0; j--) {
                    cout << buf[j];
                }

                bufidx = 0;
                cout << ' ';
            } else {
                buf[bufidx++] = s[i];
            }
        }
    }

    if (bufidx != 0) {
        for (int j = bufidx - 1; j >= 0; j--) {
            cout << buf[j];
        }
    }
    cout << '\n';

    return 0;
}