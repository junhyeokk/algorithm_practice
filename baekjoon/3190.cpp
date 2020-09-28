#include <iostream>
#include <queue>
using namespace std;

const int MAX = 101;
char board[MAX][MAX] = {0, };
int n;
deque<pair<int, int>> snake;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int cur_dir = 3;    // 오른쪽

bool isInside(int x, int y) {
    return (x >= 1 && x <= n && y >= 1 && y <= n);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int cur_time = 1;
    int k, l;
    cin >> n;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        board[y][x] = 2;    // apple
    }

    cin >> l;
    snake.push_back({1, 1});
    board[1][1] = 1;
    bool break_flag = false;
    for (int i = 0; i < l; i++) {
        int t;
        char c;
        cin >> t >> c;

        for (; cur_time <= t; cur_time++) {
            auto head = snake.front();
            auto tail = snake.back();
            // board[tail.first][tail.second] = 0;
            int nextX = head.first + dx[cur_dir];
            int nextY = head.second + dy[cur_dir];

            // cout << cur_time << ' ' << nextX << ' ' << nextY << '\n';

            if (!isInside(nextX, nextY) || board[nextX][nextY] == 1) {
                break_flag = true;
                break;
            } else if (board[nextX][nextY] == 2) {
                // board[tail.first][tail.second] = 1;
            } else if (board[nextX][nextY] == 0) {
                snake.pop_back();
                board[tail.first][tail.second] = 0;
            }

            snake.push_front({nextX, nextY});
            board[nextX][nextY] = 1;
        }

        if (c == 'D') {     // 오른쪽
            if (cur_dir == 0) cur_dir = 3;
            else if (cur_dir == 1) cur_dir = 2;
            else if (cur_dir == 2) cur_dir = 0;
            else if (cur_dir == 3) cur_dir = 1;
        } else if (c == 'L') {
            if (cur_dir == 0) cur_dir = 2;
            else if (cur_dir == 1) cur_dir = 3;
            else if (cur_dir == 2) cur_dir = 1;
            else if (cur_dir == 3) cur_dir = 0;
        }

        if (break_flag) break;
    }

    if (!break_flag) cur_time--;
    while (!break_flag) {
        cur_time++;
        auto head = snake.front();
        auto tail = snake.back();
        // board[tail.first][tail.second] = 0;
        int nextX = head.first + dx[cur_dir];
        int nextY = head.second + dy[cur_dir];

        // cout << cur_time << ' ' << nextX << ' ' << nextY << '\n';

        if (!isInside(nextX, nextY) || board[nextX][nextY] == 1) {
            break_flag = true;
            break;
        } else if (board[nextX][nextY] == 2) {
            // board[tail.first][tail.second] = 1;
        } else if (board[nextX][nextY] == 0) {
            snake.pop_back();
            board[tail.first][tail.second] = 0;
        }

        snake.push_front({nextX, nextY});
        board[nextX][nextY] = 1;
    }

    cout << cur_time << '\n';
    return 0;
}