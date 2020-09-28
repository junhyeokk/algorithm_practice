#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 9;
int n;
int arr1[MAX];
int arr2[MAX];

int cal1() {
    int ret = 0;

    for (int i = 0; i < n - 1; i++) {
        ret += abs(arr1[i] - arr1[i + 1]);
    }

    return ret;
}

int cal2() {
    int ret = 0;

    for (int i = 0; i < n - 1; i++) {
        ret += abs(arr2[i] - arr2[i + 1]);
    }

    return ret;
}

int main() {
    int answer = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        arr1[i] = arr2[i] = tmp;
    }

    do {
        int cand = cal1();
        answer = max(answer, cand);
    } while (next_permutation(arr1, arr1 + n));

    while (prev_permutation(arr2, arr2 + n)) {
        int cand = cal2();
        answer = max(answer, cand);
    }

    cout << answer << '\n';

    return 0;
}