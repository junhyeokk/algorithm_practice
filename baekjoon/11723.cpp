#include <iostream>
#include <cstring>
using namespace std;

int n;
bool s[21];
string order;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int x;
    memset(s, 0, sizeof(bool) * 21);

    cin >> n;
    while (n--) {
        cin >> order;

        if (order == "add") {
            cin >> x;

            s[x] = true;
        } else if (order == "remove") {
            cin >> x;

            s[x] = false;
        } else if (order == "check") {
            cin >> x;

            if (s[x]) cout << "1\n";
            else cout << "0\n";
        } else if (order == "toggle") {
            cin >> x;

            s[x] = !s[x];
        } else if (order == "all") {
            memset(s, 1, sizeof(bool) * 21);
        } else if (order == "empty") {
            memset(s, 0, sizeof(bool) * 21);
        }
    }

    return 0;
}