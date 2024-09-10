#include <iostream>
#include <Windows.h>
#include "GreeterStatic.h"

int main() {
	setlocale(LC_ALL, "rus");  //setting the language standard
	SetConsoleCP(1251);

	GreeterStaticLib::Greeter hello{};
	std::string name{};
	std::cout << "¬ведите им€: "; std::cin >> name;
	hello.greet(name);

	system("pause");

	return EXIT_SUCCESS;
}