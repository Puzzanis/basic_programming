#include <iostream>
#include <string>
#include "Counter.h"


int main() {
    setlocale(LC_ALL, "rus");  //setting the language standard

    Counter count{};

    std::string response;
    std::cout << "�� ������ ������� ��������� �������� ��������? ������� �� ��� ���: ";
    std::cin >> response;
    if (response == "��")
    {
        int value;
        std::cout << "������� ��������� �������� ��������: ";
        std::cin >> value;
        count.setCount(value);
    }

    for (;;)
    {
        char operation;
        std::cout << "������� ������� ('+', '-', '=' ��� 'x'): ";
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
            std::cout << "�������� �������" << std::endl;
        }
    }
    std::cout << "�� ��������!" << std::endl;

    return EXIT_SUCCESS;
}