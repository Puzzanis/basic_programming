#include <iostream>
#include <Windows.h>
#include "LeaverdDynLib.h"

int main() {
	setlocale(LC_ALL, "rus");  //setting the language standard
	SetConsoleCP(1251);

	LeaverdDynLib::Leaver hello{};
	std::string name{};
	std::cout << "¬ведите им€: "; std::cin >> name;
	hello.leave(name);

	return EXIT_SUCCESS;
}