#include <iostream>
#include <memory>
using namespace std;

int main() {
    unique_ptr<int> p1(new int(1));

    // unique_ptr<int> p2 = p1;
    //포인터 p1이 unique pointer이므로 두개의 포인터가 동시에 하나를 가르킬 수 없으므로 오류발생
    unique_ptr<int> p2 = move(p1);
    //p1이 가리키던 객체를 p2가 가리키게 하고 p1은 더 이상 객체를 가리키지 않음

    shared_ptr<int> sp1(new int(2));

    shared_ptr<int> sp2 = sp1;
    cout << sp1.use_count() << endl;
    //sp1과 sp2가 같은 객체를 가리키므로 use_count()의 결과는 2
    sp1.reset();
    //sp1이 더 이상 객체를 가리키지 않음
    sp2.reset();
    //객체를 가리키는 포인터가 모두 없어졌으므로 객체를 delete

    shared_ptr<int> sp3(new int(3));
    
    weak_ptr<int> wp = sp3;
    cout << sp3.use_count() << endl;
    //weak pointer로 가리키는 포인터를 추가할 경우 레퍼런스 카운트되지 않으므로 use_count의 결과는 여전히 1

    return 0;
}