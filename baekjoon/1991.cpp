#include <iostream>
using namespace std;

int n;
char tree[26][2];

void pre(char node) {
    if (node == '.') return;
    cout << node;
    pre(tree[node - 'A'][0]);
    pre(tree[node - 'A'][1]);
}

void in(char node) {
    if (node == '.') return;
    in(tree[node - 'A'][0]);
    cout << node;
    in(tree[node - 'A'][1]);
}

void post(char node) {
    if (node == '.') return;
    post(tree[node - 'A'][0]);
    post(tree[node - 'A'][1]);
    cout << node;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        char a, b, c;
        cin >> a >> b >> c;
        tree[a - 'A'][0] = b;
        tree[a - 'A'][1] = c;
    }

    pre('A');
    cout << '\n';
    in('A');
    cout << '\n';
    post('A');
    cout << '\n';

    return 0;
}