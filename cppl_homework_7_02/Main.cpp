#include<algorithm>
#include <iostream>
#include <set>
#include <vector>

int main()
{
	setlocale(LC_ALL, "rus");  //setting the language standard

	std::set<int> numbersSet;
	int count{ 0 };
	std::cout << "Введите количество элементов: ";
	std::cin >> count;
	std::cout << "Введите " << count << " элементов: " << std::endl;

	for (;;)
	{
		int tmp{ 0 };
		if (count == 0) break;
		std::cin >> tmp;
		numbersSet.insert(tmp);
		count--;
	}

	std::vector<int> numbersVec(numbersSet.begin(), numbersSet.end());
	std::sort(numbersVec.begin(), numbersVec.end(), std::greater<int>());
	std::cout << "[OUT]: " << std::endl; 
	for (auto const& elem : numbersVec)
	{
		std::cout << elem << std::endl;
	}

	return EXIT_SUCCESS;
}