#include <iostream>
#include <algorithm>
using namespace std;

char candy[51][51];
int max_candy = 1;
int n;

bool isInside(int x, int y) {
    return (x >= 1 && x <= n && y >= 1 && y <= n);
}

void check() {
    int cnt;
    
    for (int i = 1; i <= n; i++) {
        cnt = 1;

        for (int j = 1; j < n; j++) {
            if (candy[i][j] == candy[i][j + 1]) {
                cnt++;
            } else {
                cnt = 1;
            }

            max_candy = max(max_candy, cnt);
        }
    }

    for (int i = 1; i <= n; i++) {
        cnt = 1;

        for (int j = 1; j < n; j++) {
            if (candy[j][i] == candy[j + 1][i]) {
                cnt++;
            } else {
                cnt = 1;
            }

            max_candy = max(max_candy, cnt);
        }
    }
}

int main() {
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> candy[i][j];
        }
    }

    check();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (isInside(i + 1, j)) {
                swap(candy[i + 1][j], candy[i][j]);
                check();
                swap(candy[i + 1][j], candy[i][j]);
            }

            if (isInside(i, j + 1)) {
                swap(candy[i][j + 1], candy[i][j]);
                check();
                swap(candy[i][j + 1], candy[i][j]);
            }
        }
    }

    cout << max_candy << '\n';
    
    return 0;
}