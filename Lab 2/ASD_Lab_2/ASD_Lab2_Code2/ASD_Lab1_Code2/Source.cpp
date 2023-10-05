#include <stdlib.h>
#include <iostream>

// Определение структуры TwoInts с двумя целыми числами
struct TwoInts
{
    int a;
    int b;
};

// Определение структуры StructWithArray с массивом и указателем
struct StructWithArray
{
    int arr[4];
    int* someNumber;
};

int main()
{
    // Создание и инициализация объекта i2 типа TwoInts
    TwoInts i2 = { };
    i2.a = 5;
    i2.b = 7;

    // Вывод значений полей a и b объекта i2
    std::cout << i2.a << std::endl;
    std::cout << i2.b << std::endl;

    // Создание и инициализация объекта s типа StructWithArray
    StructWithArray s = { };
    s.arr[0] = 10;

    // Создание и инициализация еще одного объекта s1 типа StructWithArray
    StructWithArray s1 = { };
    s1.arr[0] = 15;

    // Создание указателя sPointer, указывающего на объект s
    StructWithArray* sPointer = &s;

    // Изменение значения первого элемента массива arr в объекте s через указатель
    sPointer->arr[0] = 20;

    // Вывод значения первого элемента массива arr объекта s
    std::cout << s.arr[0] << std::endl;

    // Изменение значения первого элемента массива arr объекта s напрямую
    s.arr[0] = 25;

    // Вывод значения первого элемента массива arr объекта s
    std::cout << s.arr[0] << std::endl;

    // Изменение значения первого элемента массива arr объекта s через указатель sPointer
    sPointer->arr[0] = 30;

    // Вывод значения первого элемента массива arr объекта s
    std::cout << s.arr[0] << std::endl;

    // Переключение указателя sPointer на объект s1
    sPointer = &s1;

    // Изменение значения первого элемента массива arr объекта, на который указывает sPointer
    sPointer->arr[0] = 35;

    // Вывод значения первого элемента массива arr объекта s
    std::cout << s.arr[0] << std::endl;

    // Вывод значения первого элемента массива arr объекта s1
    std::cout << s1.arr[0] << std::endl;

    // Создание массива объектов structArray типа StructWithArray
    StructWithArray structArray[2] = { };

    // Установка значения четвертого элемента массива arr в первом объекте structArray
    structArray[0].arr[3] = 77;

    // Установка указателя someNumber во втором объекте structArray на адрес четвертого элемента массива arr в первом объекте
    structArray[1].someNumber = &structArray[0].arr[3];

    // Повторное установление указателя sPointer на объект s
    sPointer = &s;

    // Создание указателя pointer, указывающего на четвертый элемент массива arr в объекте, на который указывает sPointer
    int* pointer = &sPointer->arr[3];

    // Изменение значения четвертого элемента массива arr объекта s
    s.arr[3] = 72;

    // Вывод значения, на которое указывает указатель pointer
    std::cout << *pointer;

    // Создание объекта memory типа StructWithArray и заполнение его нулями
    StructWithArray memory;
    memset(&memory, 0, sizeof(StructWithArray));

    return 0;
}
