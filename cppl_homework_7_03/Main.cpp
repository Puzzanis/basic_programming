#include <iostream>
#include "Vector.h"


int main()
{
	Vector<int> vec;
	std::cout << vec.capacity() << std::endl;
	std::cout << vec.size() << std::endl;
	vec.push_back(222);
	std::cout << vec.at(0) << std::endl;
	std::cout << vec.size() << std::endl;

	for (int i=0; i < 20; ++i)
	{
		vec.push_back(i);
	}

	std::cout << vec.capacity() << std::endl;
	std::cout << vec.size() << std::endl;

	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << vec.at(i) << std::endl;
	}

	return EXIT_SUCCESS;
}