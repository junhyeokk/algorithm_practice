#include <iostream>
using namespace std;

typedef long long ll;
const int MAX = 10001;
ll sumarr[MAX];
int n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> sumarr[i];
        sumarr[i] += sumarr[i - 1];
    }

    int low = 0;
    int cnt = 0;
    for (int high = 0; high <= n; high++) {
        while (sumarr[high] - sumarr[low] > m) low++;

        if (sumarr[high] - sumarr[low] < m) continue;
        if (sumarr[high] - sumarr[low] == m) {
            cnt++;
            continue;
        }
    }

    cout << cnt << '\n';

    return 0;
}