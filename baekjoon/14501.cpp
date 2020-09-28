#include <iostream>
#include <cstring>
using namespace std;

int arr[16];
int T[16];
int P[16];
int n;

int main() {
    int answer = 0;

    memset(arr, 0, sizeof(int) * 16);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> T[i] >> P[i];
    }

    for (int i = 1; i <= n; i++) {
        if (T[i] + i - 1 <= n) {
            if (arr[T[i] + i - 1] < arr[i - 1] + P[i]) {
                for (int j = T[i] + i - 1; j <= n; j++) {
                    arr[j] = max(arr[i - 1] + P[i], arr[j]);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        answer = max(answer, arr[i]);
    }

    cout << answer << '\n';

    return 0;
}