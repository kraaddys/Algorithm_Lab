// Файл main.cpp

#include <iostream>
#include "f.h"  // Включаем заголовочный файл, чтобы использовать функцию hello

static int hello(int Number) {

    return Number + 10;

}

int main() {
    int inputNumber = 7;  // Пример входного числа
    int result = hello(inputNumber);  // Вызываем функцию hello с входным числом

    // Выводим результат в консоль
    std::cout << "Result is: " << result << std::endl;

    return 0;
}
