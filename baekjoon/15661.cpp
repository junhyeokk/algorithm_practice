#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int mat[21][21];
int n;
int m;
int answer = 1e9;
int teamA[21];
bool visited[21];

void solve(int depth) {
    if (depth == m) {
        vector<int> teamB;
        int idx = 0;
        int a = 0, b = 0;

        for (int i = 0; i < n; i++) {
            if (i == teamA[idx]) idx++;
            else {
                teamB.push_back(i);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                a += mat[teamA[i]][teamA[j]];
                a += mat[teamA[j]][teamA[i]];
            }
        }

        for (int i = 0; i < teamB.size(); i++) {
            for (int j = i + 1; j < teamB.size(); j++) {
                b += mat[teamB[i]][teamB[j]];
                b += mat[teamB[j]][teamB[i]];
            }
        }

        answer = min(answer, abs(a - b));
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && (depth == 0 || teamA[depth - 1] < i)) {
            teamA[depth] = i;

            visited[i] = true;
            solve(depth + 1);
            visited[i] = false;
        }
    }
}

int main() {
    memset(visited, 0, sizeof(bool) * 21);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    for (int i = 1; i <= n - 1; i++) {
        m = i;
        solve(0);
    }

    cout << answer << '\n';

    return 0;
}