#include <iostream>
using namespace std;

int euclid(int a, int b) {
    int x;
    
    while (a % b) {
        x = a % b;
        a = b;
        b = x;
    }
    
    return b;
}

int main() {
    int n;
    int a, b;
    
    cin >> n;
    while (n--) {
        cin >> a >> b;
        if (a < b) {
            int tmp;
            tmp = a;
            a = b;
            b = tmp;
        }
        
        cout << a * b / euclid(a, b) << '\n';
    }
    
    return 0;
}