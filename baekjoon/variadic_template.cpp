#include <iostream>
using namespace std;

template <typename T>
double sum(T arg) {
    return arg;
}
// �����ε��� �̿��� ����� base case�� ���ص�

template <typename T, typename... Types>
double sum(T arg, Types... args) {
    return arg + sum(args...);
}
// args���� 0�� �̻��� ���ڰ� ��� �� �� ������ �̿��� ��� ǥ��

int main() {
    cout << sum(1, 2, 3, 4, 5, 6, 7) << endl;
    // sum �Լ����� 1�� �̻��� ���ڰ� ���� �� ����
    cout << sum(1.6, 2.9, 3.2, 4.8) << endl;
    // template���� ���ǵǾ����Ƿ� double type�� ���ؼ��� ��� ����

    return 0;
}