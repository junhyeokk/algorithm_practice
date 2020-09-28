#include <iostream>
using namespace std;

int main() {
    int e, s, m;
    int answer = 1;

    cin >> e >> s >> m;

    while (1) {
        if ((answer % 15 == 0 ? 15 : answer % 15) == e &&
            (answer % 19 == 0 ? 19 : answer % 19) == m &&
            (answer % 28 == 0 ? 28 : answer % 28) == s)
            break;
        else answer++;
    }

    cout << answer << '\n';

    return 0;
}