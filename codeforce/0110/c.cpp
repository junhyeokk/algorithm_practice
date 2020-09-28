#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){

    return a%b==0 ? b : gcd(b, a%b);

}

long long lcm(long long a, long long b){

    return a*b/gcd(a,b);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long x;
    long long min = 1000000000001;

    cin >> x;

    for (long long i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            if (lcm(i, x / i) == x) {
                int a = (i > x / i) ? i : x / i;

                if (a < min) min = a;
            }
        }
    }

    cout << x / min << ' ' << min << '\n';

    return 0;
}