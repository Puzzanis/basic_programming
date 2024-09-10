#include <iostream>
#include <Windows.h>
#include "GreeterStatic.h"

int main() {
	setlocale(LC_ALL, "rus");  //setting the language standard
	SetConsoleCP(1251);

	GreeterStaticLib::Greeter hello{};
	std::string name{};
	std::cout << "������� ���: "; std::cin >> name;
	hello.printMessage(name);

	return EXIT_SUCCESS;
}