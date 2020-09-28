#include <iostream>
using namespace std;

const int MAX = 500001;
int n;
char arr[MAX];

int main() {
    int answer = 1e9;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int cnt = 0;
    bool flag = false;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == 'R') flag = true;
        else if (flag) {
            cnt++;
        }
    }
    answer = min(answer, cnt);

    cnt = 0;
    flag = false;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == 'B') flag = true;
        else if (flag) {
            cnt++;
        }
    }
    answer = min(answer, cnt);

    cnt = 0;
    flag = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 'R') flag = true;
        else if (flag) {
            cnt++;
        }
    }
    answer = min(answer, cnt);

    cnt = 0;
    flag = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 'B') flag = true;
        else if (flag) {
            cnt++;
        }
    }
    answer = min(answer, cnt);

    cout << answer << '\n';

    return 0;
}