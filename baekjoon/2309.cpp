#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v(9);
    int answer[7];

    for (int i = 0; i < 9; i++) {
        cin >> v[i];
    }

    do {
        int sum = 0;

        for (int i = 0; i < 7; i++) {
            sum += v[i];
        }

        if (sum == 100) break;
    } while (next_permutation(v.begin(), v.end()));

    for (int i = 0; i < 7; i++) {
        answer[i] = v[i];
    }

    sort(answer, answer + 7);

    for (int x : answer) cout << x << '\n';

    return 0;
}