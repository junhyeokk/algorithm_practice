#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 500001;
pair<int, int> arr[MAX];
int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }

    stable_sort(arr + 1, arr + n + 1);

    for (int i = 1; i <= n; i++) {
        cout << i << ' ' << arr[i].first << ' ' << arr[i].second << '\n';
        if (arr[i + 1].second  <= i + 1) {
            cout << i << '\n';
            // break;
        }
    }

    return 0;
}