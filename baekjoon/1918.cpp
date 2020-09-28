#include <iostream>
#include <stack>
using namespace std;

int main() {
    string s;
    stack<char> stk;
    
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            stk.push(s[i]);
        } else if (s[i] == ')') {
            while (stk.top() != '(') {
                cout << stk.top();
                stk.pop();
            }
            stk.pop();
        } else if (s[i] == '+' || s[i] == '-') {
            while (!stk.empty() && (stk.top() == '*' || stk.top() == '/')) {
                cout << stk.top();
                stk.pop();
            }
            if (!stk.empty() && (stk.top() == '+' || stk.top() == '-')) {
                cout << stk.top();
                stk.pop();
            }
            stk.push(s[i]);
        } else if (s[i] == '*' || s[i] == '/') {
            if (!stk.empty() && (stk.top() == '*' || stk.top() == '/')) {
                cout << stk.top();
                stk.pop();
            }
            stk.push(s[i]);
        } else {
            cout << s[i];
        }
    }

    while (!stk.empty()) {
        cout << stk.top();
        stk.pop();
    }
    cout << '\n';

    return 0;
}