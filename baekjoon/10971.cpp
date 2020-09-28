#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 11;
int matrix[MAX][MAX];
int cand[MAX];
int n;

int main() {
    int answer = 1e9;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        cand[i] = i + 1;
    }

    do {
        int x = 0;
        bool flag = false;

        cand[n] = cand[0];
        for (int i = 0; i < n; i++) {
            if (matrix[cand[i]][cand[i + 1]] == 0) {
                flag = true;
                break;
            }

            x += matrix[cand[i]][cand[i + 1]];
        }

        if (flag) continue;
        answer = min(x, answer);
    } while (next_permutation(cand, cand + n));

    cout << answer << '\n';
    
    return 0;
}