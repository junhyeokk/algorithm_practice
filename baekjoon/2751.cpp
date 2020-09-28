#include <iostream>
using namespace std;

const int MAX = 1000001;
bool numbers[MAX * 2] = {0, };
int n;

int main() {
    cin >> n;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        numbers[num + MAX - 1] = true;
    }

    for (int i = 0; i < MAX * 2; i++) {
        if (numbers[i]) {
            cout << i - MAX + 1 << '\n';
        }
    }

    return 0;
}