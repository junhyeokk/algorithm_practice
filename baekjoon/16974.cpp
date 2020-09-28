#include <bits/stdc++.h>
using namespace std;

const int MAX = 51;
typedef long long ll;
ll patty[MAX], burger[MAX];
ll n, x;

ll solve(ll n, ll x) {
    if (n == 1) {
        if (x == 1) return 0;
        if (x >= 2 && x <= 4) return x - 1;
        if (x == 5) return 3;
    }
    if (x == 1) return 0;

    long long mid = (burger[n] + 1) / 2;
    if (x == mid) {
        return patty[n - 1] + 1;
    }
    if (x < mid) {
        return solve(n - 1, x - 1);
    }
    if (x > mid) {
        if (x == burger[n]) return patty[n];
        return patty[n - 1] + 1 + solve(n - 1, x - mid);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cur;
    cin >> n >> x;
    patty[0] = 1, burger[0] = 1;
    for (int i = 1; i <= n; i++) {
        patty[i] = patty[i - 1] * 2 + 1;
        burger[i] = burger[i - 1] * 2 + 3;
    }

    cout << solve(n, x) << '\n';

    return 0;
}