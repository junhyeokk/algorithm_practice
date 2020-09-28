#include <iostream>
using namespace std;

const int MAX = 10001;
int arr[MAX][4] = {0, };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;

    arr[1][1] = 1;
    arr[2][1] = 1;
    arr[2][2] = 1;
    arr[3][1] = 1;
    arr[3][2] = 1;
    arr[3][3] = 1;
    int calcednum = 3;
    while (t--) {
        int n;
        cin >> n;

        if (n <= calcednum) {
            cout << arr[n][1] + arr[n][2] + arr[n][3] << '\n';
        } else {
            while (calcednum != n) {
                calcednum++;

                arr[calcednum][1] = 1;
                arr[calcednum][2] = arr[calcednum - 2][1] + arr[calcednum - 2][2];
                arr[calcednum][3] = arr[calcednum - 3][1] + arr[calcednum - 3][2] + arr[calcednum - 3][3];
            }

            cout << arr[n][1] + arr[n][2] + arr[n][3] << '\n';
        }
    }

    return 0;
}