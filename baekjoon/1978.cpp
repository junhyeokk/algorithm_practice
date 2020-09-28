#include <iostream>
#include <cstring>
using namespace std;

bool eratosthenes[1001];

int main() {
    int n, tmp;
    int cnt = 0;
    memset(eratosthenes, 0, sizeof(bool) * 1001);

    for (int i = 2; i * i <= 1001; i++) {
        if (!eratosthenes[i]) {
            for (int j = i * i; j <= 1001; j += i) {
                eratosthenes[j] = true;
            }
        }
    }
    eratosthenes[1] = true;

    cin >> n;

    while (n--) {
        cin >> tmp;

        if (!eratosthenes[tmp]) cnt++;
    }

    cout << cnt << '\n';

    return 0;
}