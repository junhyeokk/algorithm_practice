#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x, y, z;
};

double dist(Point x, Point y) {
    return sqrt(pow(x.x - y.x, 2) + pow(x.y - y.y, 2) + pow(x.z - y.z, 2));
}

int main() {
    Point a, b, c;
    cin >> a.x >> a.y >> a.z >> b.x >> b.y >> b.z >> c.x >> c.y >> c.z;

    Point left, right;
    if (a.x > b.x) {
        left = b;
        right = a;
    } else {
        left = a;
        right = b;
    }

    while (left.x <= right.x) {
        
    }

    return 0;
}