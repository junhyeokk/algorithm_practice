#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<char> v;

    cin >> n;
    while (n != 1) {
        if (n > 0) {
            v.push_back((char)(n % 2 + '0'));

            n = n / 2;
            n *= -1;
        } else if (n < 0) {
            n *= -1;
            
            if (n % 2 == 0) {
                v.push_back('0');
                n = n / 2;
            } else {
                v.push_back('1');
                n += 2;
                n = n / 2;
            }
        }
    }

    v.push_back('1');
    for (auto it = v.rbegin(); it != v.rend(); it++) {
        cout << *it;
    }
    cout << '\n';

    return 0;
}