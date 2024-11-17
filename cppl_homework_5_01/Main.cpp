#include <iostream>
#include <vector>

// шаблон для единичных элементов
template<class T>
T exponent(T x)
{
	return x * x;
}

// специализация шаблона для вектора
template<>
std::vector<int> exponent(std::vector<int> x)
{
	for (auto& elem : x)
	{
		elem *= elem;
	}
	return x;
}

int main()
{
	std::cout << exponent<int>(12) << std::endl;
	
	std::vector<int> v{1,2,34,5,6};
	for (const auto& elem : exponent(v))
	{
		std::cout << elem << " ";
	}
	return EXIT_SUCCESS;
}