#include <iostream>
using namespace std;

const int MAX = 11;
int n;
int bids[MAX];
bool selected[MAX] = {0, };
int answer = -1;

void go(int depth, int score, int pos) {
    // cout << score << ' ' << pos << ' ' << depth << '\n';
    if (depth == n - 1) {
        answer = max(answer, score);
        return;
    }

    int r, l;
    for (int i = pos - 1; i >= 0; i--) {
        if (!selected[i]) {
            l = i;
            break;
        }
    }
    for (int i = pos + 1; i <= n - 1; i++) {
        if (!selected[i]) {
            r = i;
            break;
        }
    }
    score += bids[r] * bids[l];

    for (int i = 1; i <= n - 2; i++) {
        if (!selected[i]) {
            selected[i] = true;
            go(depth + 1, score, i);
            selected[i] = false;
        }
    }
    if (depth == n - 2) go(depth + 1, score, 0);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> bids[i];
    }

    for (int i = 1; i < n - 1; i++) {
        selected[i] = true;
        go(1, 0, i);
        selected[i] = false;
    }

    cout << answer << '\n';

    return 0;
}