#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int target;
int arr[21];
int answer = 0;
int output[21];
bool visited[21];

void solve(int depth) {
    if (depth == m) {
        int sum = 0;

        for (int i = 0; i < m; i++) {
            sum += arr[output[i]];
        }
        if (sum == target) answer++;

        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && (depth == 0 || output[depth - 1] < i)) {
            output[depth] = i;

            visited[i] = true;
            solve(depth + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> n >> target;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(bool) * 21);
        m = i;
        solve(0);
    }

    cout << answer << '\n';

    return 0;
}