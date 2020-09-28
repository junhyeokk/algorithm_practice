#include <iostream>
using namespace std;

int main() {
    int n;
    int pos = 1, nines = 9, jari = 1;
    int result = 0;

    cin >> n;
    while (nines < n) {
        result += (nines - pos + 1) * jari;

        nines = nines * 10 + 9;
        pos = pos * 10;
        jari++;
    }
    result += (n - pos + 1) * jari;

    cout << result << '\n';

    return 0;
}