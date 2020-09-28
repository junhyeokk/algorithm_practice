#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> A;
vector<int> B;
vector<int> output;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    A.resize(n);
    B.resize(m);
    output.resize(n + m);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }

    merge(A.begin(), A.end(), B.begin(), B.end(), output.begin());

    for (int x : output) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}