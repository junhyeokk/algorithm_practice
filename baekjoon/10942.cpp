#include <iostream>
using namespace std;

const int MAX = 2001;
char check[MAX][MAX] = {0, };
int n, m;
int inpt[MAX];

bool palin(int s, int e) {
    if (check[s][e] == 1) return true;
    else if (check[s][e] == 2) return false;

    if (s == e) {
        return true;
    } else if (e - s== 1) {
        if (inpt[s] == inpt[e]) {
            check[s][e] = 1;
            return true;
        } else {
            check[s][e] = 2;
            return false;
        }
    }

    if (inpt[s] == inpt[e]) {
        if (palin(s + 1, e - 1)) {
            check[s][e] = 1;
            return true;
        } else {
            check[s][e] = 2;
            return false;
        }
    } else {
        check[s][e] = 2;
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> inpt[i];
        check[i][i] = 1;
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;

        if (palin(start, end)) {
            check[start][end] = 1;
            cout << "1\n";
        } else {
            check[start][end] = 2;
            cout << "0\n";
        }
    }

    return 0;
}