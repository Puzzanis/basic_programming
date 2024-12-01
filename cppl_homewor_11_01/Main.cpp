#include <iostream>
#include <vector>

template<class T>
void move_vectors(std::vector<T>& vec, std::vector<T>& vec1)
{
	vec1 = std::move(vec);
}

int main()
{
	std::vector <std::string> one = { "test_string1", "test_string2" };
	std::vector <std::string> two;

	move_vectors(one, two);
	std::cout << one.size() << std::endl;
	std::cout << two.size() << std::endl;

	std::vector <int> three = { 111, 222, 333, 444 };
	std::vector <int> four;

	move_vectors(three, four);
	std::cout << three.size() << std::endl;
	std::cout << four.size() << std::endl;

	return EXIT_SUCCESS;
}