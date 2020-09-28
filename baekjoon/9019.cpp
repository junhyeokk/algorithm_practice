#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 10000;
int start, target;
char order[MAX];
int cnt[MAX];
int previous[MAX];

int orderD(int x) {
    return (2 * x) % 10000;
}

int orderS(int x) {
    if (x == 0) return 9999;
    else return x - 1;
}

int orderL(int x) {
    return (x % 1000) * 10 + x / 1000;
}

int orderR(int x) {
    return (x % 10) * 1000 + (x / 10);
}

void bfs() {
    queue<int> q;
    q.push(start);
    cnt[start] = 0;

    while (!q.empty()) {
        int l = q.size();
        bool flag = false;

        for (int i = 0; i < l; i++) {
            int cur_pos = q.front();
            q.pop();

            int result;
            result = orderD(cur_pos);
            if (cnt[result] > cnt[cur_pos] + 1) {
                // if (result == target) flag = true;
                q.push(result);
                order[result] = 'D';
                previous[result] = cur_pos;
                cnt[result] = cnt[cur_pos] + 1;
            }

            result = orderL(cur_pos);
            if (cnt[result] > cnt[cur_pos] + 1) {
                // if (result == target) flag = true;
                q.push(result);
                order[result] ='L';
                previous[result] = cur_pos;
                cnt[result] = cnt[cur_pos] + 1;
            }

            result = orderR(cur_pos);
            if (cnt[result] > cnt[cur_pos] + 1) {
                // if (result == target) flag = true;
                q.push(result);
                order[result] = 'R';
                previous[result] = cur_pos;
                cnt[result] = cnt[cur_pos] + 1;
            }

            result = orderS(cur_pos);
            if (cnt[result] > cnt[cur_pos] + 1) {
                // if (result == target) flag = true;
                q.push(result);
                order[result] = 'S';
                previous[result] = cur_pos;
                cnt[result] = cnt[cur_pos] + 1;
            }
        }

        if (flag) break;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> start >> target;
        memset(previous, -1, sizeof(int) * MAX);
        memset(order, '\0', sizeof(order));
        fill(cnt, cnt + MAX, 1e9);

        bfs();

        string answer;
        for (int i = target; i != start; i = previous[i]) {
            answer = order[i] + answer;
        }

        cout << answer << '\n';
    }

    return 0;
}