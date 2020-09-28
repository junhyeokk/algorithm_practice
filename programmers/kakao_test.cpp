#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> board1[31];
    stack<int> bascket;
    
    for (auto it = board.rbegin(); it != board.rend(); it++) {
        for (int i = 0; i < (*it).size(); i++) {
            if ((*it)[i] == 0) continue;
            board1[i + 1].push((*it)[i]);
        }
    }
    
    for (int move : moves) {
        if (board1[move].empty()) continue;
        
        int val = board1[move].top();
        board1[move].pop();
        
        if (bascket.empty()) {
            bascket.push(val);
            continue;
        }
        
        if (bascket.top() == val) {
            bascket.pop();
            answer += 2;
        } else {
            bascket.push(val);
        }
    }
    return answer;
}

int main() {
    cout << solution({{0, 0, 0, 0, 0}, {0, 0, 1, 0, 3}, {0, 2, 5, 0, 1}, {4, 2, 4, 4, 2}, {3, 5, 1, 3, 1}}, {1, 5, 3, 5, 1, 2, 1, 4}) << endl;
    return 0;
}