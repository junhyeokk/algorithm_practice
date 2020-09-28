#include <iostream>
using namespace std;

int main() {
    string inpt;
    cin >> inpt;

    int answer = 0;
    if (inpt.size() > 0) {
        if (inpt[0] == 'c') {
            answer = 26;
        } else if (inpt[0] == 'd') {
            answer = 10;
        }
    }

    for (int i = 1; i < inpt.size(); i++) {
        if (inpt[i] == 'c') {
            if (inpt[i - 1] == 'c') {
                answer *= 25;
            } else {
                answer *= 26;
            }
        } else {
            if (inpt[i - 1] == 'c') {
                answer *= 10;
            } else {
                answer *= 9;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}