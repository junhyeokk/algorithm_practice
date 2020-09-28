#include <iostream>
using namespace std;

int main() {
    string s;

    getline(cin, s);
    for (char c : s) {
        if (c >= 'A' && c <= 'Z') {
            cout << (char)((c - 'A' + 13) % 26 + 'A');
        } else if (c >= 'a' && c <= 'z') {
            cout << (char)((c - 'a' + 13) % 26 + 'a');
        } else {
            cout << c;
        }
    }
    cout << '\n';

    return 0;
}