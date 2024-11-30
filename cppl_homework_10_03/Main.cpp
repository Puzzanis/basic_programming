#include <iostream>
#include "uniquePtr.h"

int main()
{
	auto ptr = uniquePtr<int>(new int(3));
	auto ptr1 = uniquePtr<int>(new int(5));

	std::cout << *ptr << std::endl;
	std::cout << *ptr1 << std::endl;

	//ptr1 = ptr;
	std::cout << ptr.release() << std::endl;
	std::cout << ptr1.release() << std::endl;

	return EXIT_SUCCESS;
}