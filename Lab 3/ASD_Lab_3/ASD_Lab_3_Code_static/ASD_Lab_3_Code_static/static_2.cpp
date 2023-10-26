#include <iostream>

int a = 0;

void staticMemory()
{
    std::cout << "a: " << a << std::endl;
    a += 1;
}

int main()
{
    staticMemory(); // prints 0
    staticMemory(); // prints 1
    staticMemory(); // prints 2
    return 0;
}

//� ���� ���� ���������� a ��������� ��� ���������� ���������� ��� ������� staticMemory. 
//��� ��������, ��� a ����� � �������� ��� ���� ������� � ������ �����. 
//��� ����� ��������� ���� �������� ����� �������� ������� staticMemory, �� �� ������� ��������� ����, 
//��� �������� ��� ���� ������� � �����.

    //��� ������� ������ static_2 ������������� ������� (� ����� ������������� ������������� ���������� � ������ �����)?

    //�����: ������� ������� ����, ��� ���������� � ����� ��������� � ������������� static � ���������� ������� ���������.
    //static int a = 0;
    //��� ��������, ��� a ����� ����� ������ ������ �������� ����� � �� ������ ���� ������������� �� ������ ������.