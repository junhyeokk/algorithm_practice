#include <iostream>
#include <stack>
using namespace std;

const int MAX = 1000002;
stack<int> st;
string pop_str;
string inpt;
char output[MAX];

int main() {
    cin >> inpt;
    cin >> pop_str;

    int cur = 0;
    // cout << pop_str.size() << endl;
    for (int i = 0; i < inpt.size(); i++) {
        if (st.empty()) {
            if (pop_str[0] == inpt[i]) {
                if (pop_str.size() == 1) continue;
                st.push(0);
            } else {
                output[cur++] = inpt[i];
            }
        } else {
            if (pop_str[st.top() + 1] == inpt[i]) {
                st.push(st.top() + 1);

                if (st.top() + 1 == pop_str.size()) {
                    while (st.top() != 0) st.pop();
                    st.pop();
                }
            } else if (pop_str[0] == inpt[i]) {
                st.push(0);
            } else {
                int cur_x = cur + st.size() - 1;
                cur += st.size();

                while (!st.empty()) {
                    output[cur_x--] = pop_str[st.top()];
                    st.pop();
                }
                output[cur++] = inpt[i];
            }
        }
    }

    if (!st.empty()) {
        int cur_x = cur + st.size() - 1;
        cur += st.size();

        while(!st.empty()) {
            output[cur_x--] = pop_str[st.top()];
            st.pop();
        }
    }

    if (cur == 0) {
        cout << "FRULA";
    } else {
        for (int i = 0; i < cur; i++) {
            cout << output[i];
        }
    }
    cout << '\n';

    return 0;
}