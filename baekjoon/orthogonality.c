#include <stdio.h>

int main() {
    int a[1] = { 1 };

    if (!a)
        printf("pass\n");
        // 포인터에 대해서도 !연산 사용이 가능하므로 오류가 발생하지 않음.
        // 따라서 일반적으로 사용되지 않는 포인터에 대한 not 연산으로 동작함.

    return 0;
}