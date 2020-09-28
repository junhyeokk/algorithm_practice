#include <iostream>
#include <cstring>
using namespace std;

int n;
char arr[11][11];
int output[11];
// bool visited[21];

bool possible(int depth, int x) {
    for (int i = depth; i >= 0; i--) {
        int sum = x;
        output[depth] = 0;

        for (int j = depth; j >= i; j--) {
            sum += output[j];
        }

        if ((arr[i][depth] == '+' && sum > 0) || (arr[i][depth] == '-' && sum < 0) || (arr[i][depth] == '0' && sum == 0)) {}
        else {
            return false;
        }
    }

    return true;
}

void solve(int depth) {
    if (depth == n) {
        for (int i = 0; i < n; i++) {
            cout << output[i] << ' ';
        }
        cout << '\n';
        exit(0);
        return;
    }

    for (int i = -10; i <= 10; i++) {
        // if (!visited[i + 10]) {
            if (possible(depth, i)) {
                output[depth] = i;

                // visited[i + 10] = true;
                solve(depth + 1);
                // visited[i + 10] = false;
            }
        // }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    // memset(visited, 0, sizeof(bool) * 21);
    solve(0);

    return 0;
}