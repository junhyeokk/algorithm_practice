#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 1000010;

bool eratosthenes[MAX];
vector<int> primes;

int main() {
    int t;
    int n, cnt;

    memset(eratosthenes, 0, sizeof(bool) * MAX);

    for (int i = 2; i * i < MAX; i++) {
        if (!eratosthenes[i]) {
            for (int j = i * i; j < MAX; j += i) {
                eratosthenes[j] = true;
            }
        }
    }
    eratosthenes[0] = eratosthenes[1] = true;

    for (int i = 0; i < MAX; i++) {
        if (!eratosthenes[i]) primes.push_back(i);
    }

    cin >> t;
    while (t--) {
        cin >> n;
        cnt = 0;

        for (int x : primes) {
            if (x > n / 2) break;

            if (!eratosthenes[n - x]) cnt++;
        }

        cout << cnt << '\n';
    }

    return 0;
}