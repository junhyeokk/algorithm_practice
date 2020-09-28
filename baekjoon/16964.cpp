#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 100001;
int n;
vector<int> graph[MAX];
bool visited[MAX];

int main() {
    memset(visited, 0, sizeof(bool) * MAX);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    stack<int> st;
    int tmp;
    cin >> tmp;
    
    if (tmp != 1) {
        cout << "0\n";
        return 0;
    }

    st.push(1);
    visited[1] = true;

    for (int i = 0; i < n - 1; i++) {
        cin >> tmp;

        while (graph[st.top()].empty()) st.pop();
        int cur = st.top();
        // cout << cur << "!\n";

        auto pos = find(graph[cur].begin(), graph[cur].end(), tmp);

        if (pos != graph[cur].end()) {
            if (!visited[tmp]) {
                visited[tmp] = true;
                st.push(tmp);
                
                graph[cur].erase(find(graph[cur].begin(), graph[cur].end(), tmp));
                graph[tmp].erase(find(graph[tmp].begin(), graph[tmp].end(), cur));
            } else {
                cout << "0\n";
                return 0;
            }
        } else {
            cout << "0\n";
            return 0;
        }
    }

    cout << "1\n";
    return 0;
}