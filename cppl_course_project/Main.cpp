﻿#include <iostream>
#include "Parser.h"

int main()
{
	setlocale(LC_ALL, "RU");

	try
	{
		Parser parser("config.ini");
		auto value = parser.getValue<int>("general.distributed");
		std::cout << "value	= " << value << std::endl;

		auto value1 = parser.getValue<std::string>("general.pvss_path");
		std::cout << "value 1 = " << value1 << std::endl;

		auto value2 = parser.getValue<double>("general.valueChangeTimeDiff");
		std::cout << "value 2 = " << value2 << std::endl;

		auto value3 = parser.getValue<float>("general.valueChangeTimeDiff");
		std::cout << "value 3 = " << value3 << std::endl;

		auto value4 = parser.getValue<float>("mod.maxQueueSize");
		std::cout << "value 4 = " << value4 << std::endl;

	}
	catch (const std::runtime_error& ex)
	{
		std::cout << "Ошибка при чтении файла. " << ex.what() << std::endl;
	}
	catch (const std::out_of_range& ex)
	{
		std::cout << "Строка не может быть преобразована в число. " << ex.what() << std::endl;
	}
	catch (const std::invalid_argument& ex)
	{
		std::cout << "Строка не может быть преобразована в число. " << ex.what() << std::endl;
	}

	return EXIT_SUCCESS;
}