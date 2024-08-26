#include <iostream>
#include <string>
#include "Counter.h"


int main() {
    setlocale(LC_ALL, "rus");  //setting the language standard

    Counter count{};

    std::string response;
    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::cin >> response;
    if (response == "да")
    {
        int value;
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> value;
        count.setCount(value);
    }

    for (;;)
    {
        char operation;
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> operation;
        if (operation == 'x') break;
        switch (operation)
        {
        case '+':
            count.increment();
            break;
        case '-':
            count.decrement();
            break;
        case '=':
            std::cout << count.getCount() << std::endl;
            break;
        default:
            std::cout << "Неверная команда" << std::endl;
        }
    }
    std::cout << "До свидания!" << std::endl;

    return EXIT_SUCCESS;
}