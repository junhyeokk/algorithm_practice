#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[100001];
int answer;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int answer = (n - k) % (k - 1) != 0 ? (n - k) / (k - 1) + 2 : (n - k) / (k - 1) + 1;
    cout << answer << '\n';

    return 0;
}