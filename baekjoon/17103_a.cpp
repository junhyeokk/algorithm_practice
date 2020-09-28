#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;

bool prime[maxn];
vector<int> p;

int main(void) {
    ios_base::sync_with_stdio(0);   cin.tie(0);
    prime[0] = prime[1] = true;
    for(int i = 2; i < maxn; ++i) if(!prime[i]) {
        p.push_back(i);
        for(long long j = 1LL * i * i; j < maxn; j += i)    prime[j] = true;
    }
    int T;  cin >> T;
    while(T--) {
        int n;  cin >> n;
        int ans = 0;
        for(auto i : p) {
            if(i > n / 2)   break;
            ans += !prime[n - i];
        }
        cout << ans << '\n';
    }
    return 0;
}