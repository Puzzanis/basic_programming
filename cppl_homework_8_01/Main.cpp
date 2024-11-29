#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

template<class T>
void printVec(T& mass)
{
	for (const auto& elem : mass)
	{
		std::cout << elem << '\t';
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<int> vec = { 1, 1, 2, 5, 6, 1, 2, 4 };

	printVec<std::vector<int>>(vec);
	
	//удаление дубликатов с помощью set
	std::set<int> Set(vec.begin(), vec.end());
	printVec<std::set<int>>(Set);
	
	//удаление дубликатов с помощью unique
	std::sort(vec.begin(), vec.end());
	auto it = std::unique(vec.begin(), vec.end());
	vec.erase(it, vec.end());
	printVec<std::vector<int>>(vec);


	return EXIT_SUCCESS;
}