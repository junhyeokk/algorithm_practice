#include <iostream>
using namespace std;

int main() {
    int i;
    int result = 1;

    cin >> i;
    while (i) {
        result *= i;
        i--;
    }

    cout << result << '\n';

    return 0;
}