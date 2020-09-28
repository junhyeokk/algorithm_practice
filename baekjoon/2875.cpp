#include <iostream>
using namespace std;

int main() {
    int N, M, K;

    cin >> N >> M >> K;

    cout << min(min(M, N / 2), (N + M - K) / 3) << '\n';

    return 0;
}