#include <iostream>
#include <stack>
using namespace std;

double numbers[26];

int main() {
    int n;
    string s;
    stack<double> stk;

    cin >> n;
    cin >> s;

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '*' && s[i] != '+' && s[i] != '-' && s[i] != '/') {
            stk.push(numbers[s[i] - 'A']);
        } else {
            double a, b;
            b = (double)(stk.top());
            stk.pop();
            a = (double)(stk.top());
            stk.pop();

            if (s[i] == '*') {
                stk.push(a * b);
            } else if (s[i] == '+') {
                stk.push(a + b);
            } else if (s[i] == '-') {
                stk.push(a - b);
            } else if (s[i] == '/') {
                stk.push(a / b);
            }
        }
    }

    printf("%.2f\n", stk.top());

    return 0;
}