#include <iostream>
#include <Windows.h>
#include "Function.h"



int main()
{
    setlocale(LC_ALL, "rus");  //setting the language standard
    SetConsoleCP(1251);

    int forbidden_length{ 1000 };
    std::cout << "Введите запретную длину: "; std::cin >> forbidden_length;

    while (true) {
        std::string str{};
        std::cout << "Введите слово: "; std::cin >> str;
        try {
            std::cout << "Длина слова \"" << str << "\" равна " << function(str, forbidden_length) << std::endl;
        }
        catch (const std::exception& error) {
            std::cout << error.what() << std::endl;
            return EXIT_SUCCESS;
        }
    }
    
    return EXIT_SUCCESS;
}