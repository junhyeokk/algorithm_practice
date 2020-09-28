#include <iostream>
using namespace std;

int main() {
    string n;
    int b;
    int answer = 0, multiplier = 1;

    cin >> n >> b;
    for (auto it = n.rbegin(); it != n.rend(); it++) {
        if ('A' <= *it && 'Z' >= *it) {
            answer += (*it - 'A' + 10) * multiplier;
        } else {
            answer += (*it - '0') * multiplier;
        }

        multiplier *= b;
    }

    cout << answer << '\n';

    return 0;
}