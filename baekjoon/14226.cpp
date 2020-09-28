#include <bits/stdc++.h>
using namespace std;

const int MAX = 10001;
int s;
bool visited[MAX][MAX]; // (s, clip)
// int m[MAX]; //s
queue<pair<int, pair<int, int>>> q;  //(s, (clip, cnt))

int main() {
    int answer;

    cin >> s;

    memset(visited, 0, sizeof(bool) * MAX * MAX);
    // memset(m, 0, sizeof(int) * MAX);

    q.push({1, {0, 0}});
    visited[1][0] = true;

    while (1) {
        int cur_s = q.front().first;
        int cur_clip = q.front().second.first;
        int cur_cnt = q.front().second.second;
        q.pop();

        if (cur_s - 1 >= 2 && !visited[cur_s - 1][cur_clip]) {
            visited[cur_s - 1][cur_clip] = true;
            // m[cur_s - 1] = cur_cnt + 1;
            q.push({cur_s - 1, {cur_clip, cur_cnt + 1}});

            if (cur_s - 1 == s) {
                answer = cur_cnt + 1;
                break;
            }
        }

        if (!visited[cur_s][cur_s]) {
            visited[cur_s][cur_s] = true;
            // m[cur_s] = ;
            q.push({cur_s, {cur_s, cur_cnt + 1}});
        }

        if (cur_clip < MAX && !visited[cur_s + cur_clip][cur_clip]) {
            visited[cur_s + cur_clip][cur_clip] = true;
            // m[cur_s + 
            q.push({cur_s + cur_clip, {cur_clip, cur_cnt + 1}});

            if (cur_s + cur_clip == s) {
                answer = cur_cnt + 1;
                break;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}