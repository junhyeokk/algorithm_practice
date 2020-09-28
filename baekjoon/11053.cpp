#include <iostream>
using namespace std;

int num[1001];
int arr[1001] = {0};

int main() {
    int n;
    int ans = 1;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        arr[i] = 1;
    }

    arr[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (num[i] > num[j]) arr[i] = max(arr[i], arr[j] + 1);
        }

        ans = max(ans, arr[i]);
    }
    cout << ans << '\n';

    return 0;
}