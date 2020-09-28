#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 100001;
int map[MAX];
bool visited[MAX];
int s, b;

bool isInside(int pos) {
    return (pos >= 0 && pos < MAX);
}

int main() {
    cin >> s >> b;

    memset(map, 0, sizeof(int) * MAX);
    memset(visited, 0, sizeof(bool) * MAX);
    queue<int> q;

    if (s == b) {
        cout << "0\n";
        return 0;
    }

    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        if (isInside(cur + 1) && !visited[cur + 1]) {
            map[cur + 1] = map[cur] + 1;
            visited[cur + 1] = true;
            q.push(cur + 1);
            
            if (cur + 1 == b) {
                cout << map[cur + 1] << '\n';
                break;
            }
        }
        
        if (isInside(cur - 1) && !visited[cur - 1]) {
            map[cur - 1] = map[cur] + 1;
            visited[cur - 1] = true;
            q.push(cur - 1);

            if (cur - 1 == b) {
                cout << map[cur - 1] << '\n';
                break;
            }
        }
        
        if (isInside(2 * cur) && !visited[2 * cur]) {
            map[2 * cur] = map[cur] + 1;
            visited[2 * cur] = true;
            q.push(2 * cur);

            if (2 * cur == b) {
                cout << map[2 * cur] << '\n';
                break;
            }
        }
    }

    return 0;
}