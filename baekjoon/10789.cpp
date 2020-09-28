#include <iostream>
using namespace std;

char arr[5][15];

int main() {
    int longest = -1;
    for (int i = 0; i < 5; i++) {
        string tmp;
        cin >> tmp;

        for (int j = 0; j < tmp.size(); j++) {
            arr[i][j] = tmp[j];
        }

        longest = max(longest, (int)tmp.size());
    }

    for (int i = 0; i < longest; i++) {
        for (int j = 0; j < 5; j++) {
            if (arr[j][i] == 0) continue;
            cout << arr[j][i];
        }
    }
    cout << '\n';

    return 0;
}