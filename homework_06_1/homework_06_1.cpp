#include <iostream>
#include "Maths.h"


int main() {
	setlocale(LC_ALL, "rus");  //setting the language standard

	int first_number{};
	std::cout << "Введите первое число: "; std::cin >> first_number;
	int second_number{};
	std::cout << "Введите второе число: "; std::cin >> second_number;
	int num_func{};
	std::cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): "; std::cin >> num_func;


	switch (num_func)
	{
	case 1:
		std::cout << first_number << " плюс " << second_number << " = " << sum(first_number, second_number) << std::endl;
		break;
	case 2:
		std::cout << first_number << " минус " << second_number << " = " << diff(first_number, second_number) << std::endl;
		break;
	case 3:
		std::cout << first_number << " умножить " << second_number << " = " << multiplication(first_number, second_number) << std::endl;
		break;
	case 4:
		std::cout << first_number << " разделить " << second_number << " = " << division(first_number, second_number) << std::endl;
		break;
	case 5:
		std::cout << first_number << " в степени " << second_number << " = " << pow(first_number, second_number) << std::endl;
		break;
	default:
		break;
	}
	return EXIT_SUCCESS;
}
