#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;
    int answer = 0;
    int idx = 0;
    // while (s[idx] != '-' && s[idx] != '+') {
    //     answer = answer * 10 + s[idx] - '0';
    //     idx++;
    // }

    bool flag = false;
    int cur_num = 0;
    for (; idx < s.size(); idx++) {
        if (s[idx] != '+' && s[idx] != '-') {
            cur_num = cur_num * 10 + s[idx] - '0';
        } else {
            if (flag) {
                answer -= cur_num;
            } else {
                answer += cur_num;
            }
            
            if (s[idx] == '-') {
                flag = true;
            }
            cur_num = 0;
        }
    }

    if (flag) {
        answer -= cur_num;
    } else {
        answer += cur_num;
    }
    cout << answer << '\n';

    return 0;
}