#include <iostream>
using namespace std;

const int MAX = 1001;
int candy[MAX][MAX];
int n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> candy[i][j];
        }
    }

    for (int i = 1; i < n; i++) {
        candy[i][0] += candy[i - 1][0];
    }

    for (int i = 1; i < m; i++) {
        candy[0][i] += candy[0][i - 1];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            candy[i][j] += max(candy[i - 1][j], max(candy[i][j - 1], candy[i - 1][j - 1]));
        }
    }
    cout << candy[n - 1][m - 1] << '\n';

    return 0;
}