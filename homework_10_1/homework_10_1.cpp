﻿#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");  //setting the language standard
	SetConsoleCP(1251);

	std::string name{};
	std::cout << "Введите имя: "; std::cin >> name;
	std::cout << "Здравствуйте, " << name << '!' << std::endl;

	system("pause");
	return 0;
}
