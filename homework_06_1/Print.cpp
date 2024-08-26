#include <iostream>
#include "Maths.h"

void print(int num_func, int first_number, int second_number)
{
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
		std::cout << "¬веден некорректный номер операции" << std::endl;
		break;
	}
}