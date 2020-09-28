#include <iostream>
using namespace std;

const int MAX = 10001;
int arr[MAX] = {0, };
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        arr[tmp]++;
    }

    for (int i = 1; i < MAX; i++) {
        if (arr[i] != 0) {
            for (int j = 0; j < arr[i]; j++) {
                cout << i << '\n';
            }
        }
    }

    return 0;
}