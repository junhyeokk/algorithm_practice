#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 9;

bool visited[MAX];
int arr[MAX];
int m, n;

void solve(int cnt) {
    if (cnt == n) {
        for (int i = 0; i < cnt; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';

        return;
    }

    for (int i = 1; i <= m; i++) {
        if (!visited[i]) {
            arr[cnt] = i;

            visited[i] = true;
            solve(cnt + 1);
            visited[i] = false;
        }
    }
}

int main() {
    memset(visited, 0, sizeof(bool) * MAX);

    cin >> m >> n;
    solve(0);
    
    return 0;
}