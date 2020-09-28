#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
    int max1 = -1, max2 = -1;
    while (a / 10) {
        max1 = max(max1, a % 10);
        a = a / 10;
    }
    max1 = max(max1, a % 10);
    while (b / 10) {
        max2 = max(max2, b % 10);
        b = b / 10;
    }
    max2 = max(max2, b % 10);
    return max1 > max2;
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), cmp);
    for (int i : numbers) {
        answer = answer + to_string(i);
    }
    return answer;
}

int main() {
	string s = "00000";
	if (stoi(s) == 0) cout << "a\n";

	return 0;
}