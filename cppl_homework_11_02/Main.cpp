#include <iostream>
#include "BigInteger.h"

int main()
{
	auto number1 = BigInteger("-9852455");
	auto number2 = BigInteger("-414575");

	auto result = number1 + number2;

	return EXIT_SUCCESS;
}