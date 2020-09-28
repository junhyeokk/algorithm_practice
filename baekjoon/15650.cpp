#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 9;

bool visited[MAX];
int arr[MAX];
int n, m;

void solve(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < cnt; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = arr[cnt - 1]; i <= n; i++) {
        if (!visited[i]) {
            arr[cnt] = i;

            visited[i] = true;
            solve(cnt + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    memset(visited, 0, sizeof(bool) * MAX);

    solve(0);

    return 0;
}