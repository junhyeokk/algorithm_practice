#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100001;
int n;
pair<int, int> arr[MAX];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        cin >> arr[i].second;
    }

    sort(arr, arr + n);

    for (int i = 0; i < n; i++) {
        cout << arr[i].first << ' ' << arr[i].second << '\n';
    }

    return 0;
}