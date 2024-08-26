#include <iostream>
#include "Print.h"


int main() {
	setlocale(LC_ALL, "rus");  //setting the language standard

	int first_number{};
	std::cout << "Введите первое число: "; std::cin >> first_number;
	int second_number{};
	std::cout << "Введите второе число: "; std::cin >> second_number;
	int num_func{};
	std::cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): "; std::cin >> num_func;

	print(num_func, first_number, second_number);

	return EXIT_SUCCESS;
}
