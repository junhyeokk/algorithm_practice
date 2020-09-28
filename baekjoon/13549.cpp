#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100001;
int s, e;
bool visited[MAX];

auto cmp = [](pair<int, int> &a, pair<int, int> &b) {
    if (a.first == b.first) return a.second > b.second;
    else return a.first > b.first;
};

priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

int bfs() {
    pq.push({0, s});
    visited[s] = true;

    while (!pq.empty()) {
        int cur_time = pq.top().first;
        int cur_pos = pq.top().second;
        pq.pop();
        // cout << cur_time << ' ' << cur_pos << endl;

        if (cur_pos == e) return cur_time;

        if (cur_pos * 2 < MAX && !visited[cur_pos * 2]) {
            // if (cur_pos * 2 == e) return cur_time;
            visited[cur_pos * 2] = true;
            pq.push({cur_time, cur_pos * 2});
        }
        if (cur_pos + 1 < MAX && !visited[cur_pos + 1]) {
            // if (cur_pos + 1 == e) return cur_time + 1;
            visited[cur_pos + 1] = true;
            pq.push({cur_time + 1, cur_pos + 1});
        }
        if (cur_pos - 1 >= 0 && !visited[cur_pos - 1]) {
            // if (cur_pos - 1 == e) return cur_time + 1;
            visited[cur_pos - 1] = true;
            pq.push({cur_time + 1, cur_pos - 1});
        }
    }
}

int main() {
    cin >> s >> e;

    cout << bfs() << '\n';

    return 0;
}