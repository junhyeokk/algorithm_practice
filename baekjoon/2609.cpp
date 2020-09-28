#include <iostream>
using namespace std;

int euclid(int a, int b) {
    int x;

    while (a % b) {
        x = a % b;
        a = b;
        b = x;
    }

    return b;
}

int main() {
    int x, y;

    cin >> x >> y;
    if (x < y) {
        int tmp;
        tmp = x;
        x = y;
        y = tmp;
    }

    int gcd = euclid(x, y);
    cout << gcd << '\n';
    cout << x * y / gcd << '\n';

    return 0;
}