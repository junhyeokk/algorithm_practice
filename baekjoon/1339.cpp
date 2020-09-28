#include <iostream>
#include <cstring>
using namespace std;

int alphabet[26] = {0, };
int num_check[10];
int n;
int cnt = 1;
string arr[11];
bool visited[10];
int answer = -1;

void go(int depth) {
    if (depth == cnt - 1) {
        int cand = 0;

        for (int i = 0; i < n; i++) {
            int mult = 1;

            for (int j = arr[i].size() - 1; j >= 0; j--) {
                cand += num_check[alphabet[arr[i][j] - 'A'] - 1] * mult;
                mult *= 10;
            }
        }

        answer = max(answer, cand);
        return;
    }

    for (int i = 9; i >= 0; i--) {
        if (!visited[i]) {
            visited[i] = true;
            num_check[depth] = i;
            go(depth + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        for (char c : arr[i]) {
            if (alphabet[c - 'A'] == 0) {
                alphabet[c - 'A'] = cnt;
                cnt++;
            }
        }
    }

    memset(visited, 0, sizeof(bool) * 10);
    go(0);
    cout << answer << '\n';

    return 0;
}