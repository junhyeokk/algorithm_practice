#include <iostream>
#include <queue>
using namespace std;

auto cmp = [](const int &a, const int &b) {
    if (abs(a) == abs(b)) return a > b;
    else return abs(a) > abs(b);
};

priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

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