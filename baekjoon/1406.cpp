#include <iostream>
using namespace std;

char r[600001];
char l[600001];

int main() {
    string a;
    int rcur = 0, lcur = 0;
    int n;

    cin >> a;
    for (int i = 0; i < a.size(); i++) {
        r[rcur] = a[i];
        rcur++;
    }

    cin >> n;
    while (n--) {
        char order;
        cin >> order;

        if (order == 'L' && rcur > 0) {
            l[lcur] = r[rcur - 1];
            lcur++;
            rcur--;
        } else if (order == 'D' && lcur > 0) {
            r[rcur] = l[lcur - 1];
            rcur++;
            lcur--;
        } else if (order == 'B' && rcur > 0) {
            rcur--;
        } else if (order == 'P') {
            char c;
            cin >> c;

            r[rcur] = c;
            rcur++;
        }
    }

    for (int i = 0; i < rcur; i++) {
        cout << r[i];
    }

    for (int i = lcur - 1; i >= 0; i--) {
        cout << l[i];
    }

    cout << '\n';

    return 0;
}