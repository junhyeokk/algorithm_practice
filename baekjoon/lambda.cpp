#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> test = {3, 1, 2};
    
    sort(test.begin(), test.end());
    // stl algorithm의 sort 함수를 비교 함수 없이 실행했을 때엔 기본적으로 오름차순 정렬
    
    sort(test.begin(), test.end(), [](int a, int b)->bool {return a > b;});
    // sort 함수의 비교함수 부분을 람다 표현식으로 전달하여 내림차순 정렬로 바꿈

    for (auto i : test) cout << i << endl;

    return 0;
}