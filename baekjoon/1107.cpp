#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 1000001;

int target;
bool broken[10] = {0, };
int n;

int count_button(int channel) {
    int cnt = 0;

    if (channel == 0) {
        if (broken[0]) return MAX;
        else return 1;
    }

    while (channel) {
        if (broken[channel % 10]) {
            cnt = MAX;
            break;
        }

        channel /= 10;
        cnt++;
    }

    return cnt;
}

int main() {
    int result = MAX;

    cin >> target;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;

        cin >> tmp;
        broken[tmp] = true;
    }

    result = target >= 100 ? target - 100 : 100 - target;

    for (int i = 0; i < MAX; i++) {
        int cand2;

        cand2 = count_button(i) + abs(target - i);
        result = min(result, cand2);
    }

    cout << result << '\n';

    return 0;
}