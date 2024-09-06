#include <iostream>
#include "Fraction.h"

int main() {

	setlocale(LC_ALL, "rus");  //setting the language standard

	int numerator_1{};
	int denominator_1{};
	std::cout << "Введите числитель дроби 1: "; std::cin >> numerator_1;
	std::cout << "Введите знаменатель дроби 1: "; std::cin >> denominator_1;

	int numerator_2{};
	int denominator_2{};
	std::cout << "Введите числитель дроби 2: "; std::cin >> numerator_2;
	std::cout << "Введите знаменатель дроби 2: "; std::cin >> denominator_2;

	Fraction f1{ numerator_1,  denominator_1 };
	Fraction f2{ numerator_2,  denominator_2 };
	
	Fraction f3{ f1 + f2 };
	std::cout << f1.get_numerator() << '/' << f1.get_denominator() << '+' << f2.get_numerator() << '/' << f2.get_denominator() << '=' << f3.get_numerator() << '/' << f3.get_denominator() << '\n';
	
	Fraction f4{ f1 - f2 };
	std::cout << f1.get_numerator() << '/' << f1.get_denominator() << '-' << f2.get_numerator() << '/' << f2.get_denominator() << '=' << f4.get_numerator() << '/' << f4.get_denominator() << '\n';
	
	Fraction f5{ f1 * f2 };
	std::cout << f1.get_numerator() << '/' << f1.get_denominator() << '*' << f2.get_numerator() << '/' << f2.get_denominator() << '=' << f5.get_numerator() << '/' << f5.get_denominator() << '\n';

	Fraction f6{ f1 / f2 };
	std::cout << f1.get_numerator() << '/' << f1.get_denominator() << '/' << f2.get_numerator() << '/' << f2.get_denominator() << '=' << f6.get_numerator() << '/' << f6.get_denominator() << '\n';

	
	std::cout << "++" << f1.get_numerator() << '/' << f1.get_denominator() << '*' << f2.get_numerator() << '/' << f2.get_denominator() << '=';
	Fraction f7{ ++f1 * f2 };
	std::cout << f7.get_numerator() << '/' << f7.get_denominator() << '\n';

	std::cout << "Значение дроби 1 = " << f1.get_numerator() << '/' << f1.get_denominator() << '\n';

	
	std::cout << f1.get_numerator() << '/' << f1.get_denominator() << "-- " << '*' << f2.get_numerator() << '/' << f2.get_denominator() << '=';
	Fraction f8{ f1-- * f2 };
	std::cout << f8.get_numerator() << '/' << f8.get_denominator() << '\n';

	std::cout << "Значение дроби 1 = " << f1.get_numerator() << '/' << f1.get_denominator() << '\n';

	return 0;
}