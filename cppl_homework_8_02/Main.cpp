#include <iostream>
#include<list>
#include <set>
#include <vector>

template<class T>
void printCont(const T& mass)
{
	for (auto it = mass.begin(); it != mass.end(); it++)
	{
		std::cout << *it << '\t';
	}
	std::cout << std::endl;
}

int main()
{
	std::set<std::string> test_set = { "one", "two", "three", "four" };
	printCont<std::set<std::string>>(test_set); // four one three two. помните почему такой порядок? :)

	std::list<std::string> test_list = { "one", "two", "three", "four" };
	printCont<std::list<std::string>>(test_list); // one, two, three, four

	std::vector<std::string> test_vector = { "one", "two", "three", "four" };
	printCont<std::vector<std::string>>(test_vector); // one, two, three, four


	return EXIT_SUCCESS;
}