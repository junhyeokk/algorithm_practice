#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.begin(), people.end());
    int smallest = 0, biggest = people.size() - 1;

    int cur_lim = limit;
    while (smallest <= biggest) {
        if (smallest == biggest) {
            answer++;
            break;
        } else if (people[smallest] + people[biggest] > cur_lim) {
            answer++;
            biggest--;
            cur_lim = limit;
        } else if (people[smallest] + people[biggest] == cur_lim) {
            answer++;
            biggest--;
            smallest++;
            cur_lim = limit;
        } else {
            cur_lim -= people[smallest];
            smallest++;
        }
    }

    return answer;
}

int main() {
    int n, limit;
    vector<int> p;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        p.push_back(tmp);
    }
    cin >> limit;

    cout << solution(p, limit) << endl;

    return 0;
}