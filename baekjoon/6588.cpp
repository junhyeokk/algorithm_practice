#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAX = 1000001;

bool eratosthenes[MAX];
vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int tmp;
    memset(eratosthenes, 0, sizeof(bool) * MAX);

    for (int i = 0; i < MAX; i++) {
        eratosthenes[i] = false;
    }

    for (int i = 2; i * i < MAX; i++) {
        if (!eratosthenes[i]) {
            if (i != 2) v.push_back(i);
            for (int j = i * i; j < MAX; j += i) {
                eratosthenes[j] = true;
            }
        }
    }

    eratosthenes[0] = true;
    eratosthenes[1] = true;

    while (1) {
        cin >> tmp;

        if (tmp == 0) break;

        bool flag = false;

        for (int i = 0; i < v.size(); i++) {
            if (!eratosthenes[tmp - v[i]]) {
                cout << tmp << " = " << v[i] << " + " << tmp - v[i] << '\n';
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }

    return 0;
}