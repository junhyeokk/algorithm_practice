#include <iostream>
#include <vector>
using namespace std;

vector<int> numbers;

int main() {
    int a, b, n, x = 0;
    int multiplier = 1;
    string output;

    cin >> a >> b;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        numbers.push_back(tmp);
    }

    for (auto it = numbers.rbegin(); it != numbers.rend(); it++) {
        x += (*it) * multiplier;
        multiplier *= a;
    }

    numbers.clear();
    while (1) {
        numbers.push_back(x % b);

        if (x / b == 0) break;
        x /= b;
    }

    for (int i = numbers.size() - 1; i >= 0; i--) {
        cout << numbers[i];

        if (i != 0) cout << " ";
    }
    cout << '\n';

    return 0;
}