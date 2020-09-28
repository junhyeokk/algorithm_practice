#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, max;
    char temp, count;
    bool countOn;

    cin >> n;
    for (int i = 0; i < n; i++) {
        max = 0;
        count = 0;
        countOn = false;

        cin >> m;

        for (int j = 0; j < m; j++) {
            cin >> temp;

            if (temp == 'A') {
                countOn = true;
                count = 0;
            } else if (temp == 'P' && countOn) {
                count++;

                if (count > max) max = count;
            }
        }

        cout << max << '\n';
    }

    return 0;
}