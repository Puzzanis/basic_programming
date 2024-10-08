#include <algorithm>
#include <iostream>
#include <vector>
#include "Count_Sort.h"


void print(std::vector<int>& arr1, std::vector<int>& arr2)
{
	std::cout << "Исходный массив: ";
	copy(arr1.begin(), arr1.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	std::cout << "Отсортированный массив: ";
	copy(arr2.begin(), arr2.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	std::cout << std::endl;
}


int main()
{
	setlocale(LC_ALL, "rus");  //setting the language standard
	std::vector<int> arr1{ 19, 14, 22, 22, 17, 22, 13, 21, 20, 24, 18, 10, 17, 16, 17, 20, 22, 11, 20, 16, 14, 13, 10, 22, 18, 14, 16, 24, 19, 17 };
	std::vector<int> arr2{ 16, 17, 14, 20, 22, 20, 17, 22, 16, 19, 23, 24, 20, 22, 21, 18, 14, 16, 17, 21, 10, 11, 19, 23, 11, 11, 17, 17, 11, 21, 17, 11, 17, 16, 12, 11, 16, 22, 23, 16 };
	std::vector<int> arr3{ 21, 15, 19, 18, 23, 12, 18, 18, 19, 23, 12, 20, 15, 22, 21, 18, 19, 20, 12, 16, 20, 14, 17, 13, 10, 23, 19, 14, 10, 22, 19, 12, 24, 23, 22, 15, 13, 22, 18, 18, 11, 23, 24, 17, 10 };

	std::vector<int> arr4 = count_Sort(arr1, *std::max_element(arr1.begin(), arr1.end()));
	std::vector<int> arr5 = count_Sort(arr2, *std::max_element(arr2.begin(), arr2.end()));
	std::vector<int> arr6 = count_Sort(arr3, *std::max_element(arr3.begin(), arr3.end()));
	
	print(arr1, arr4);
	print(arr2, arr5);
	print(arr3, arr6);

	return EXIT_SUCCESS;
}