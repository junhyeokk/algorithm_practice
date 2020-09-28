#include <iostream>
#include <queue>
#include <set>
using namespace std;

typedef long long ll;

struct Rocks {
    ll a_, b_, c_;
};

bool operator<(const Rocks &a, const Rocks &b) {
    if (a.a_ != b.a_) return (a.a_ < b.a_);
    else if (a.b_ != b.b_) return (a.b_ < b.b_);
    else return (a.c_ < b.c_);
}

ll a, b, c;

int isokay(ll a, ll b, ll c) {
    // if (a < 0 || b < 0 || c < 0) return -1;
    // if (a == b && b != c) return -1;
    // if (a == c && a != b) return -1;
    // if (b == c && a != b) return -1;
    if (a == b && b == c) return 1;
    else return 0;
}

int main() {
    bool flag = false;
    cin >> a >> b >> c;

    if (a == b && b == c) {
        cout << "1\n";
        return 0;
    }

    queue<Rocks> q;
    set<Rocks> s;
    q.push({a, b, c});
    s.insert({a, b, c});
    while (!q.empty()) {
        int cur_a = q.front().a_, cur_b = q.front().b_, cur_c = q.front().c_;
        q.pop();

        if (cur_a > cur_b) {
            if (s.count({cur_a - cur_b, cur_b * 2, cur_c}) == 0) {
                s.insert({{cur_a - cur_b, cur_b * 2, cur_c}});
                q.push({cur_a - cur_b, cur_b * 2, cur_c});
            }
        } else {
            int x = isokay(cur_a * 2, cur_b - cur_a, cur_c);
            if (x == 1) {
                flag = true;
                break;
            } else if (x == 0) 
                if (s.count({cur_a * 2, cur_b - cur_a, cur_c}) == 0) {
                    s.insert({cur_a * 2, cur_b - cur_a, cur_c});
                    q.push({cur_a * 2, cur_b - cur_a, cur_c});
                }
        }

        if (cur_a > cur_c) {
            if (s.count({cur_a - cur_c, cur_b, cur_c * 2}) == 0) {
                s.insert({cur_a - cur_c, cur_b, cur_c * 2});
                q.push({cur_a - cur_c, cur_b, cur_c * 2});
            }
        } else {
            int x = isokay(cur_a * 2, cur_b, cur_c - cur_a);
            if (x == 1) {
                flag = true;
                break;
            } else if (x == 0)
                if (s.count({cur_a * 2, cur_b, cur_c - cur_a}) == 0) {
                    s.insert({cur_a * 2, cur_b, cur_c - cur_a});
                    q.push({cur_a * 2, cur_b, cur_c - cur_a});
                }
        }

        if (cur_b > cur_c) {
            if (s.count({cur_a, cur_b - cur_c, cur_c * 2}) == 0) {
                s.insert({cur_a, cur_b - cur_c, cur_c * 2});
                q.push({cur_a, cur_b - cur_c, cur_c * 2});
            }
        } else {
            int x = isokay(cur_a, cur_b * 2, cur_c - cur_b);
            if (x == 1) {
                flag = true;
                break;
            } else if (x == 0)
                if (s.count({cur_a, cur_b * 2, cur_c - cur_b}) == 0) {
                    s.insert({cur_a, cur_b * 2, cur_c - cur_b});
                    q.push({cur_a, cur_b * 2, cur_c - cur_b});
                }
        }
    }

    if (flag) cout << "1\n";
    else cout << "0\n";

    return 0;
}