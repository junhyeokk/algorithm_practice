#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1001;
int times[MAX];
int n;
int total = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> times[i];
    }

    sort(times, times + n);

    int answer = 0;
    for (int i = 0; i < n; i++) {
        total += times[i];
        answer += total;
    }

    cout << answer << '\n';

    return 0;
}