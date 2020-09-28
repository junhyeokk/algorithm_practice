#include <iostream>
using namespace std;

const int MAX = 100001;
int n;
bool start[MAX];
bool target[MAX];
int answer = 2e9;

void go(int idx, int cnt) {
    if (idx == n - 1) {
        if (start[idx - 1] != target[idx - 1]) {
            start[idx - 1] = !start[idx - 1];
            start[idx] = !start[idx];

            if (start[idx] == target[idx]) {
                answer = min(answer, cnt + 1);
            }

            start[idx - 1] = !start[idx - 1];
            start[idx] = !start[idx];

            return;
        }

        if (start[idx] == target[idx]) {
            answer = min(answer, cnt);
        }

        return;
    }

    if (start[idx - 1] != target[idx - 1]) {
        start[idx - 1] = !start[idx - 1];
        start[idx] = !start[idx];
        start[idx + 1] = !start[idx + 1];

        go(idx + 1, cnt + 1);

        start[idx - 1] = !start[idx - 1];
        start[idx] = !start[idx];
        start[idx + 1] = !start[idx + 1];
    } else {
        go(idx + 1, cnt);
    }
}

int main() {
    cin >> n;
    string tmp;
    cin >> tmp;
    for (int i = 0; i < n; i++) {
        if (tmp[i] == '1') start[i] = true;
        else start[i] = false;
    }

    cin >> tmp;
    for (int i = 0; i < n; i++) {
        if (tmp[i] == '1') target[i] = true;
        else target[i] = false;
    }

    go(1, 0);

    start[0] = !start[0];
    start[1] = !start[1];

    go(1, 1);

    if (answer == 2e9) cout << -1 << '\n';
    else cout << answer << '\n';

    return 0;
}