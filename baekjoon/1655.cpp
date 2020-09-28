#include <iostream>
#include <queue>
#include <functional>
using namespace std;

priority_queue<int, vector<int>, less<int>> pq1;    // 큰거
priority_queue<int, vector<int>, greater<int>> pq2; // 작은거

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, tmp;
    cin >> n;

    while (n--) {
        cin >> tmp;

        if (pq1.empty() && pq2.empty()) {
            pq1.push(tmp);
            cout << tmp << '\n';
            continue;
        } else if (pq2.empty()) {
            if (tmp < pq1.top()) {
                pq2.push(pq1.top());
                pq1.pop();
                pq1.push(tmp);
            } else {
                pq2.push(tmp);
            }
            cout << pq1.top() << '\n';
            continue;
        } else if (pq1.empty()) {
            if (tmp > pq2.top()) {
                pq1.push(pq2.top());
                pq2.pop();
                pq2.push(tmp);
            } else {
                pq1.push(tmp);
            }
            cout << pq1.top() << '\n';
            continue;
        }

        if (tmp > pq2.top()) {
            pq2.push(tmp);

            if (pq2.size() > pq1.size()) {
                pq1.push(pq2.top());
                pq2.pop();
            }
        } else {
            pq1.push(tmp);

            if (pq1.size() > pq2.size() + 1) {
                pq2.push(pq1.top());
                pq1.pop();
            }
        }

        cout << pq1.top() << '\n';
    }

    return 0;
}