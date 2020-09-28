#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> test = {3, 1, 2};
    
    sort(test.begin(), test.end());
    // stl algorithm�� sort �Լ��� �� �Լ� ���� �������� ���� �⺻������ �������� ����
    
    sort(test.begin(), test.end(), [](int a, int b)->bool {return a > b;});
    // sort �Լ��� ���Լ� �κ��� ���� ǥ�������� �����Ͽ� �������� ���ķ� �ٲ�

    for (auto i : test) cout << i << endl;

    return 0;
}