#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100001;
int n;
pair<int, string> arr[MAX];

bool cmp(const pair<int, string> &a, const pair<int, string> &b) {
    if (a.first != b.first) return a.first < b.first;
    else return false;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    stable_sort(arr, arr + n, cmp);

    for (int i = 0; i < n; i++) {
        cout << arr[i].first << ' ' << arr[i].second << '\n';
    }

    return 0;
}