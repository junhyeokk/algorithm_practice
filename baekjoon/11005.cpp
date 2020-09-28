#include <iostream>
using namespace std;

int main() {
    int n, b;
    string s;

    cin >> n >> b;
    while (1) {
        if (n % b > 9) {
            s = (char)(n % b + 'A' - 10) + s;
        } else if (n % b <= 9) {
            s = (char)(n % b + '0') + s;
        }

        if (n / b == 0) break;
        n = n / b;
    }

    cout << s << '\n';

    return 0;
}