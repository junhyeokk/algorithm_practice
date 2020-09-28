#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 3001;
vector<int> graph[MAX];
bool visited[MAX];
bool is_cycle[MAX];
int how_far_from_cycle[MAX];
int n, node_in_cycle;

int find_cycle(int x, int parent) {
    if (visited[x]) {
        node_in_cycle = x;
        is_cycle[x] = true;
        return 1;      // found cycle
    }
    visited[x] = true;

    for (int next : graph[x]) {
        if (next != parent) {
            int res = find_cycle(next, x);

            if (res == 1 && !is_cycle[x]) {
                is_cycle[x] = true;
                return 1;
            }
        }
    }

    return 0;
}

void numbering(int x, int num) {
    visited[x] = true;
    if (is_cycle[x]) how_far_from_cycle[x] = 0;
    else how_far_from_cycle[x] = num;

    for (int next : graph[x]) {
        if (!visited[next]) {
            if (is_cycle[x]) numbering(next, num);
            else numbering(next, num + 1);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    memset(visited, 0, sizeof(bool) * MAX);
    memset(is_cycle, 0, sizeof(bool) * MAX);

    find_cycle(1, 1);

    memset(visited, 0, sizeof(bool) * MAX);

    numbering(node_in_cycle, 1);

    for (int i = 1; i <= n; i++) {
        cout << how_far_from_cycle[i] << ' ';
    }
    cout << '\n';

    return 0;
}