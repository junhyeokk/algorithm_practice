#include <iostream>
#include <memory>
using namespace std;

int main() {
    unique_ptr<int> p1(new int(1));

    // unique_ptr<int> p2 = p1;
    //������ p1�� unique pointer�̹Ƿ� �ΰ��� �����Ͱ� ���ÿ� �ϳ��� ����ų �� �����Ƿ� �����߻�
    unique_ptr<int> p2 = move(p1);
    //p1�� ����Ű�� ��ü�� p2�� ����Ű�� �ϰ� p1�� �� �̻� ��ü�� ����Ű�� ����

    shared_ptr<int> sp1(new int(2));

    shared_ptr<int> sp2 = sp1;
    cout << sp1.use_count() << endl;
    //sp1�� sp2�� ���� ��ü�� ����Ű�Ƿ� use_count()�� ����� 2
    sp1.reset();
    //sp1�� �� �̻� ��ü�� ����Ű�� ����
    sp2.reset();
    //��ü�� ����Ű�� �����Ͱ� ��� ���������Ƿ� ��ü�� delete

    shared_ptr<int> sp3(new int(3));
    
    weak_ptr<int> wp = sp3;
    cout << sp3.use_count() << endl;
    //weak pointer�� ����Ű�� �����͸� �߰��� ��� ���۷��� ī��Ʈ���� �����Ƿ� use_count�� ����� ������ 1

    return 0;
}