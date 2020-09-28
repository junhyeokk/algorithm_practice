#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    char tmp;
    int numL = 0, numR = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;

        if (tmp == 'L') numL++;
        else numR++;
    }

    cout << numL + numR + 1 << '\n';

    return 0;
}