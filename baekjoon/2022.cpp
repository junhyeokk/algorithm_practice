#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x, y, c;
    cin >> x >> y >> c;

    double left = 0, right = max(x, y);
    double answer;
    while (left <= right) {
        double mid = (left + right) / 2;

        double a = sqrt(x * x - mid * mid);
        double b = sqrt(y * y - mid * mid);

        if (a * b / (a + b) >= c) {
            left = mid + 0.00001;
        } else {
            right = mid - 0.00001;
        }
        answer = mid;
    }

    // cout.setprecision
    cout << answer << '\n';

    return 0;
}