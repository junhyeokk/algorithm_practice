#include <iostream>
#include <vector>
using namespace std;

int sudoku[10][10];
vector<pair<int, int>> blankspace;

bool ispossible(int x, int y) {
    for (int i = 0; i < 9; i++) {
        if (y == i) continue;
        if (sudoku[x][y] == sudoku[x][i]) return false;
    }
    for (int i = 0; i < 9; i++) {
        if (x == i) continue;
        if (sudoku[i][y] == sudoku[x][y]) return false;
    }
    for (int i = (x / 3) * 3; i < (x / 3) * 3 + 3; i++) {
        for (int j = (y / 3) * 3; j < (y / 3) * 3 + 3; j++) {
            if (i == x && j == y) continue;
            if (sudoku[i][j] == sudoku[x][y]) return false;
        }
    }

    return true;
}

void go(int depth) {
    if (depth == blankspace.size()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << sudoku[i][j] << ' ';
            }
            cout << '\n';
        }
        exit(0);
    }

    int curX = blankspace[depth].first;
    int curY = blankspace[depth].second;
    for (int i = 1; i <= 9; i++) {
        sudoku[curX][curY] = i;
        if (ispossible(curX, curY)) {
            go(depth + 1);
        }
        sudoku[curX][curY] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
            if (sudoku[i][j] == 0) {
                blankspace.push_back({i, j});
            }
        }
    }
    cout << "h\n";
    go(0);

    return 0;
}