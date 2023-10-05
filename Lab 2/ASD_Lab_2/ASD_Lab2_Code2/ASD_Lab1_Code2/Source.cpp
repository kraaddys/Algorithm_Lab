#include <stdlib.h>
#include <iostream>

// ����������� ��������� TwoInts � ����� ������ �������
struct TwoInts
{
    int a;
    int b;
};

// ����������� ��������� StructWithArray � �������� � ����������
struct StructWithArray
{
    int arr[4];
    int* someNumber;
};

int main()
{
    // �������� � ������������� ������� i2 ���� TwoInts
    TwoInts i2 = { };
    i2.a = 5;
    i2.b = 7;

    // ����� �������� ����� a � b ������� i2
    std::cout << i2.a << std::endl;
    std::cout << i2.b << std::endl;

    // �������� � ������������� ������� s ���� StructWithArray
    StructWithArray s = { };
    s.arr[0] = 10;

    // �������� � ������������� ��� ������ ������� s1 ���� StructWithArray
    StructWithArray s1 = { };
    s1.arr[0] = 15;

    // �������� ��������� sPointer, ������������ �� ������ s
    StructWithArray* sPointer = &s;

    // ��������� �������� ������� �������� ������� arr � ������� s ����� ���������
    sPointer->arr[0] = 20;

    // ����� �������� ������� �������� ������� arr ������� s
    std::cout << s.arr[0] << std::endl;

    // ��������� �������� ������� �������� ������� arr ������� s ��������
    s.arr[0] = 25;

    // ����� �������� ������� �������� ������� arr ������� s
    std::cout << s.arr[0] << std::endl;

    // ��������� �������� ������� �������� ������� arr ������� s ����� ��������� sPointer
    sPointer->arr[0] = 30;

    // ����� �������� ������� �������� ������� arr ������� s
    std::cout << s.arr[0] << std::endl;

    // ������������ ��������� sPointer �� ������ s1
    sPointer = &s1;

    // ��������� �������� ������� �������� ������� arr �������, �� ������� ��������� sPointer
    sPointer->arr[0] = 35;

    // ����� �������� ������� �������� ������� arr ������� s
    std::cout << s.arr[0] << std::endl;

    // ����� �������� ������� �������� ������� arr ������� s1
    std::cout << s1.arr[0] << std::endl;

    // �������� ������� �������� structArray ���� StructWithArray
    StructWithArray structArray[2] = { };

    // ��������� �������� ���������� �������� ������� arr � ������ ������� structArray
    structArray[0].arr[3] = 77;

    // ��������� ��������� someNumber �� ������ ������� structArray �� ����� ���������� �������� ������� arr � ������ �������
    structArray[1].someNumber = &structArray[0].arr[3];

    // ��������� ������������ ��������� sPointer �� ������ s
    sPointer = &s;

    // �������� ��������� pointer, ������������ �� ��������� ������� ������� arr � �������, �� ������� ��������� sPointer
    int* pointer = &sPointer->arr[3];

    // ��������� �������� ���������� �������� ������� arr ������� s
    s.arr[3] = 72;

    // ����� ��������, �� ������� ��������� ��������� pointer
    std::cout << *pointer;

    // �������� ������� memory ���� StructWithArray � ���������� ��� ������
    StructWithArray memory;
    memset(&memory, 0, sizeof(StructWithArray));

    return 0;
}
