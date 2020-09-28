#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    bool islands[101];
    memset(islands, 0, sizeof(bool) * 101);
    if (n == 1) return 0;
    
    sort(costs.begin(), costs.end(), cmp);

    for (auto i : costs) {
        cout << i[2] << '!' << endl;
    }
    islands[costs[0][0]] = islands[costs[0][1]] = true;
    answer += costs[0][2];
    int cnt = 1;
    for (int i = 1; i < costs.size(); i++) {
        if (cnt == n - 1) break;
        if (islands[costs[i][0]] && islands[costs[i][1]]) {
            continue;
        }
        islands[costs[i][0]] = islands[costs[i][1]] = true;
        answer += costs[i][2];
        cnt++;
    }
    return answer;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> inpt(n);
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vector<int> tmp(3);
        tmp[0] = a;
        tmp[1] = b;
        tmp[2] = c;
        inpt[i] = tmp;
    }

    cout << solution(n, inpt) << endl;

    return 0;
}