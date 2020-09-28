#include <iostream>
#include <algorithm>
using namespace std;

int l, c;
char arr[16];
char output[16];
bool visited[16];
int check[2];
//a e i u o

void solve(int depth) {
    if (depth == l) {
        if (check[0] >= 1 && check[1] >= 2) {
            for (int i = 0; i < l; i++) {
                cout << output[i];
            }
            cout << '\n';
        }
        
        return;
    }

    for (int i = 0; i < c; i++) {
        if (!visited[i] && (depth == 0 || output[depth - 1] < arr[i])) {
            output[depth] = arr[i];

            if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'u' || arr[i] == 'o') {
                check[0]++;
            } else {
                check[1]++;
            }
            visited[i] = true;
            solve(depth + 1);
            visited[i] = false;
            if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'u' || arr[i] == 'o') {
                check[0]--;
            } else {
                check[1]--;
            }
        }
    }
}

int main() {
    cin >> l >> c;
    fill(visited, visited + 16, false);
    fill(check, check + 2, 0);

    for (int i = 0; i < c; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + c);
    solve(0);

    return 0;
}