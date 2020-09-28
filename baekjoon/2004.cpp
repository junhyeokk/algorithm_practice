#include <iostream>
#define ll long long
using namespace std;

pair<ll, ll> zeros(int x) {
    ll cnt2 = 0, cnt5 = 0;
    int tmp;

    tmp = x;
    while (tmp / 5 != 0) {
        cnt5 += tmp / 5;
        tmp /= 5;
    }

    tmp = x;
    while (tmp / 2 != 0) {
        cnt2 += tmp / 2;
        tmp /= 2;
    }

    return make_pair(cnt2, cnt5);
}

int main() {
    int n, m;

    cin >> n >> m;

    pair<ll, ll> numn = zeros(n);
    pair<ll, ll> numm = zeros(m);
    pair<ll, ll> numn_m = zeros(n - m);

    cout << min(numn.first - numm.first - numn_m.first, numn.second - numm.second - numn_m.second) << '\n';
    
    return 0;
}