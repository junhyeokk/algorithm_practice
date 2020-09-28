#include <iostream>
using namespace std;

int main() {
    long long a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    long long answer = a * x + b * y;
    int banban = 1;
    while (banban <= x || banban <= y) {
        int xx = (x - banban) >= 0 ? x - banban : 0;
        int yy = (y - banban) >= 0 ? y - banban : 0;
        answer = min(answer, xx * a + yy * b + banban * c * 2);
        banban++;
    }

    cout << answer << '\n';
    return 0;
}