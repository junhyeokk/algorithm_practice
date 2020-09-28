#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100001;
int n;
pair<int, int> arr[MAX];

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if (a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        cin >> arr[i].second;
    }

    sort(arr, arr + n, cmp);

    for (int i = 0; i < n; i++) {
        cout << arr[i].first << ' ' << arr[i].second << '\n';
    }

    return 0;
}