#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

typedef long long ll;
const int MAX = 10001;
int n, m;
vector<pair<int, int>> islands[MAX];
bool visited[MAX] = {0, };
int answer_dist = -1;
int s, e;

bool bfs(int dist) {
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == e) {
            return true;
        }

        for (auto next : islands[cur]) {
            if (!visited[next.first] && next.second >= dist) {
                visited[next.first] = true;
                q.push(next.first);
            }
        }
    }

    return false;
}

int main() {
    int left = 1, right = 1000000000;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        islands[a].push_back({b, c});
        islands[b].push_back({a, c});
    }
    
    cin >> s >> e;

    while (left <= right) {
        int mid = (left + right) / 2;
        
        memset(visited, 0, sizeof(visited));
        
        if (bfs(mid)) {
            answer_dist = max(answer_dist, mid);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << answer_dist << '\n';
    return 0;
}