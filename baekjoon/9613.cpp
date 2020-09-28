#include <iostream>
#define ll long long
using namespace std;

int arr[101];

int euclid(int a, int b) {
    int x;

    while (a % b) {
        x = a % b;
        a = b;
        b = x;
    }

    return b;
}

int main() {
    int t;
    int n;
    ll answer;

    cin >> t;
    while (t--) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        answer = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j]) {
                    answer += euclid(arr[i], arr[j]);
                } else {
                    answer += euclid(arr[j], arr[i]);
                }
            }
        }

        cout << answer << '\n';
    }

    return 0;
}