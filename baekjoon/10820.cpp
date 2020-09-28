#include <iostream>
using namespace std;

int main() {
    int lower, upper, number, space;
    string s;
    char buffer;

    while (getline(cin, s)) {
        // cin >> buffer;
        lower = upper = number = space = 0;

        for (char c : s) {
            if (c >= 'A' && c <= 'Z') {
                upper++;
            } else if (c >= 'a' && c <= 'z') {
                lower++;
            } else if (c >= '0' && c <= '9') {
                number++;
            } else if (c == ' ') {
                space++;
            }
        }

        cout << lower << ' ' << upper << ' ' << number << ' ' << space << '\n';
    }

    return 0;
}