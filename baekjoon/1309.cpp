#include <iostream>
using namespace std;

const int MAX = 100001;
const int DIV = 9901;

int arr[MAX][3] = {0, };

int main() {
    int n;

    arr[1][0] = 1;
    arr[1][1] = 1;
    arr[1][2] = 1;

    cin >> n;
    for (int i = 2; i <= n; i++) {
        arr[i][0] = (arr[i - 1][0] + arr[i - 1][1] + arr[i - 1][2]) % DIV;
        arr[i][1] = (arr[i - 1][0] + arr[i - 1][2]) % DIV;
        arr[i][2] = (arr[i - 1][0] + arr[i - 1][1]) % DIV;
    }

    cout << (arr[n][0] + arr[n][1] + arr[n][2]) % DIV << '\n';

    return 0;
}