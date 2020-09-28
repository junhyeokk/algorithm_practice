#include <iostream>
using namespace std;

int q[25000001];

int main() {
    int N, K;
    int f = 0, b = 0;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        q[b] = i;
        b++;
    }

    cout << "<";
    while (N--) {
        for (int i = 1; i < K; i++) {
            q[b] = q[f];
            f++; b++;
        }

        cout << q[f];
        f++;
        if (N != 0) cout << ", ";
    }
    cout << ">\n";

    return 0;
}