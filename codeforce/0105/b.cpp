#include <bits/stdc++.h>
using namespace std;

unsigned int cards[1501][31];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // memset(cards, )
    
    int n, m;
    int cnt = 0;
    char tmp;
    bool isSet;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tmp;
            // if (tmp == 'S') cards[i][j] = ;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                isSet = true;

                for (int x = 0; x < m; x++) {
                    if (cards[i][x] == cards[j][x] && cards[i][x] == cards[k][x] && cards[j][x] == cards[k][x]) continue;
                    else if (cards[i][x] != cards[j][x] && cards[i][x] != cards[k][x] && cards[j][x] != cards[k][x]) continue;
                    else {
                        isSet = false;
                        break;
                    }
                }

                if (isSet) cnt++;
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}