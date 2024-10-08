#include <iostream>
#include <vector>
#include <iterator>
#include "Quick_sort.h"


void print(std::vector<int>& arr1)
{
	copy(arr1.begin(), arr1.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}

int main()
{
	setlocale(LC_ALL, "rus");  //setting the language standard
	std::vector<int> arr1{ 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
	std::vector<int> arr2{ 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
	std::vector<int> arr3{ 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };


	std::cout << "Исходный массив: "; print(arr1);
	std::cout << "Отсортированный массив: "; quickSort(&arr1, 0, arr1.size() - 1); print(arr1);

	std::cout << "Исходный массив: "; print(arr2);
	std::cout << "Отсортированный массив: "; quickSort(&arr2, 0, arr2.size() - 1); print(arr2);

	std::cout << "Исходный массив: "; print(arr3);
	std::cout << "Отсортированный массив: "; quickSort(&arr3, 0, arr3.size() - 1); print(arr3);
	

	


	return EXIT_SUCCESS; 
}