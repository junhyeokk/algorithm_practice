#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int n;
priority_queue<int, vector<int>, less<int>> q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    int tmp;
    while (n--) {
        cin >> tmp;

        if (tmp != 0) {
            q.push(tmp);
        } else {
            if (q.empty()) {
                cout << "0\n";
                continue;
            }
            cout << q.top() << '\n';
            q.pop();
        }
    }

    return 0;
}