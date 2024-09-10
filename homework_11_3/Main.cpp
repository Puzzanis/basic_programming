#include <iostream>
#include <Windows.h>
#include "Lib/LeaverdDynLib.h"

int main()
{
	setlocale(LC_ALL, "rus");  //setting the language standard
	SetConsoleCP(1251);

	LeaverdDynLib::Leaver hello{};
	std::string name{};
	std::cout << "Введите имя: "; std::cin >> name;
	hello.leave(name);

	system("pause");

	return EXIT_SUCCESS;
}
