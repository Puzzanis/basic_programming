#include <iostream>
#include <vector>
#include <iterator>
#include "mergeSort.h"

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

	std::vector<int> arr1{ 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
	std::vector<int> arr2 = mergeSort(arr1);
	std::vector<int> arr3{ 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
	std::vector<int> arr4 = mergeSort(arr3);
	std::vector<int> arr5{ 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
	std::vector<int> arr6 = mergeSort(arr5);
	
	print(arr1, arr2);
	print(arr3, arr4);
	print(arr5, arr6);
	

	return EXIT_SUCCESS;
}