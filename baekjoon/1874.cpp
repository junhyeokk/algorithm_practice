#include <iostream>
#include <cstring>
using namespace std;

int buf[100005];
int stack[100005];
char a[200000];

int main() {
    int n;
    int cur = 0, num = 0, acur = 0;
    bool flag = true;
    // string o;

    memset(stack, -1, sizeof(int) * 100001);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> buf[i];
    }

    for (int i = 1; i <= n; i++) {
        while (stack[cur] < buf[i]) {
            cur++; num++;
            stack[cur] = num;
            // o = o + "+\n";
            a[acur++] = '+';
        }

        if (stack[cur] == buf[i]) {
            cur--;
            // o = o + "-\n";
            a[acur++] = '-';

        } else {
            flag = false;
            break;
        }
    }

    if (flag) {
        for (int i = 0; i < acur; i++) {
            cout << a[i] << '\n';
        }
    } else {
        cout << "NO\n";
    }

    return 0;
}