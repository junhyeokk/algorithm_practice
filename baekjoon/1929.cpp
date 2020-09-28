#include <iostream>
#include <cstring>
#define MAX 1000001
using namespace std;

bool eratosthenes[MAX];

int main() {
    int a, b;

    memset(eratosthenes, 0, sizeof(bool) * MAX);
    for (int i = 2; i * i < MAX; i++) {
        if (!eratosthenes[i]) {
            for (int j = i * i; j < MAX; j += i) {
                eratosthenes[j] = true;
            }
        }
    }
    eratosthenes[1] = true;

    cin >> a >> b;

    for (int i = a; i <= b; i++) {
        if (!eratosthenes[i]) {
            cout << i << '\n';
        }
    }

    return 0;
}