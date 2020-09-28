#include <iostream>
using namespace std;

struct Point { int x, y; };

int main() {
    int a {1};
    int b[3] {1, 2, 3};
    Point p {4, 5};
    // 각각 다른 방식으로 초기화되던 타입들을 {} 표현을 이용해 일관적인 방법으로 초기화

    return 0;
}