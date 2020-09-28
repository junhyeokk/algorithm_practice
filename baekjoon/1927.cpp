#include <iostream>
#include <queue>
#include <functional>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, tmp;
    cin >> n;

    while (n--) {
        cin >> tmp;

        if (tmp == 0) {
            if (pq.empty()) {
                cout << "0\n";
                continue;
            }
            cout << pq.top() << '\n';
            pq.pop();
        } else {
            pq.push(tmp);
        }
    }

    return 0;
}