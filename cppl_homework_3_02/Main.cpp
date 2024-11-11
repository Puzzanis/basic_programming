#include "Smart_array.h"

int main()
{
	setlocale(LC_ALL, "rus");  //setting the language standard

	try {
		Smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);

		Smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);

		std::cout << arr.get_element(1) << std::endl;
		std::cout << arr.getSize() << std::endl;
		std::cout << new_array.get_element(1) << std::endl;
		std::cout << new_array.getSize() << std::endl;

		arr = new_array;

		std::cout << arr.get_element(1) << std::endl;
		std::cout << arr.getSize() << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	return 0;
}