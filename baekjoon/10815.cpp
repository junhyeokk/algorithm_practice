#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M, tmp;
    multiset<int> cards;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        cards.insert(tmp);
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> tmp;

        // if (cards.find(tmp) != cards.end()) cout << "1";
        // else cout << "0";
        cout << cards.count(tmp);

        if (i == M - 1) cout << "\n";
        else cout << " ";
    }

    return 0;
}