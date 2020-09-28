#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 9;
int arr[MAX];
int output[MAX];
bool visited[MAX];
int n, m;

void solve(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < cnt; i++) {
            cout << output[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            output[cnt] = arr[i];

            visited[i] = true;
            solve(cnt + 1);
            visited[i] = false;
        }
    }
}

int main() {
    fill(visited, visited + MAX, 0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    solve(0);

    return 0;
}