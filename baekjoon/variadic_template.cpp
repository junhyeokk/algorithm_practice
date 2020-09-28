#include <iostream>
using namespace std;

template <typename T>
double sum(T arg) {
    return arg;
}
// 오버로딩을 이용해 재귀의 base case를 정해둠

template <typename T, typename... Types>
double sum(T arg, Types... args) {
    return arg + sum(args...);
}
// args에는 0개 이상의 인자가 모두 들어갈 수 있음을 이용해 재귀 표현

int main() {
    cout << sum(1, 2, 3, 4, 5, 6, 7) << endl;
    // sum 함수에는 1개 이상의 인자가 사용될 수 있음
    cout << sum(1.6, 2.9, 3.2, 4.8) << endl;
    // template으로 정의되었으므로 double type에 대해서도 계산 가능

    return 0;
}