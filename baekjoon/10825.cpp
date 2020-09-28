#include <iostream>
#include <algorithm>
using namespace std;

struct People {
    int guk, yung, su;
    string name;

    bool operator< (People b) {
        if (this->guk != b.guk) return this->guk > b.guk;
        else if (this->yung != b.yung) return this->yung < b.yung;
        else if (this->su != b.su) return this->su > b.su;
        else return this->name < b.name;
    }
};

const int MAX = 100001;
int n;
People arr[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].name >> arr[i].guk >> arr[i].yung >> arr[i].su;
    }

    sort(arr, arr + n);

    for (int i = 0; i < n; i++) {
        cout << arr[i].name << '\n';
    }

    return 0;
}