#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAX = 200001;
int n;
ll sumarr[MAX];
ll arr[MAX];
ll colors[MAX];
pair<int, pair<int, int>> cp[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cp[i].second.first >> cp[i].first;
        cp[i].second.second = i;
    }

    sort(cp, cp + n);
    for (int i = 0; i < n; i++) {
        sumarr[i + 1] += cp[i].first + sumarr[i];
    }

    int minus = 0;
    for (int i = 0; i < n; i++) {
        colors[cp[i].second.first] += cp[i].first;
        if (i != 0 && cp[i].first == cp[i - 1].first) {
            if (cp[i].second.first == cp[i - 1].second.first) {
                arr[cp[i].second.second] = arr[cp[i - 1].second.second];
                minus += cp[i].first;
                continue;
            }
            minus += cp[i].first;
        } else {
            minus = 0;
        }
        arr[cp[i].second.second] = sumarr[i + 1] - colors[cp[i].second.first] - minus;
        // arr[cp[i].second.second] = arr[cp[i].second.second] > 0 ? arr[cp[i].second.second] : 0;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << '\n';
    }

    return 0;
}