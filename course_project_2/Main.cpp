#include <iostream>
#include "Lib/Ground/Camel/Camel.h"

int main()
{
	setlocale(LC_ALL, "rus");  //setting the language standard

	std::cout << "Hello CMake." << std::endl;
	Camel camel{ "Верблюд", 10, 30, 5 };
	int res = camel.movement(4500);
	std::cout << res << std::endl;
	return EXIT_SUCCESS;
}
