#include <iostream>
using namespace std;

const int MAX = 10000001;

int aritosthenes[MAX] = {false,};

int main() {
    int n;

    aritosthenes[0] = aritosthenes[1] = true;
    for (int i = 2; i * i < MAX; i++) {
        if (!aritosthenes[i]) {
            for (int j = i * i; j < MAX; j += i) aritosthenes[j] = true;
        }
    }

    cin >> n;
    for (int i = 2; i < MAX; i++) {
        if (aritosthenes[i]) continue;

        while (n % i == 0) {
            cout << i << '\n';
            n = n / i;
        }

        if (!aritosthenes[n]) {
            cout << n << '\n';
            break;
        }
    }

    return 0;
}