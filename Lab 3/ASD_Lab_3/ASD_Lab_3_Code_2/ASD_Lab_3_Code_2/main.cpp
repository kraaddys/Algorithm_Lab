// ���� main.cpp

#include <iostream>
#include "f.h"  // �������� ������������ ����, ����� ������������ ������� hello

static int hello(int Number) {

    return Number + 10;

}

int main() {
    int inputNumber = 7;  // ������ �������� �����
    int result = hello(inputNumber);  // �������� ������� hello � ������� ������

    // ������� ��������� � �������
    std::cout << "Result is: " << result << std::endl;

    return 0;
}
