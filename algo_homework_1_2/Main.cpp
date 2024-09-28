#include <iostream>
#include <vector>

int array_serch(std::vector<int>, int);

int main() {

	setlocale(LC_ALL, "rus");  //setting the language standard

	std::vector<int> arr = { 3, 3, 4, 7, 7, 7, 11, 13, 13 };
	int value{};
	std::cout << "Введите точку отсчета в диаппазоне от " << arr.front() << " до " << arr.back() << " :"; std::cin >> value;

	
	int rez = array_serch(arr, value);
	if (rez != -1) { std::cout << "Количество элементов больше чем " << value << " равно " << rez << std::endl; }
	else { std::cout << "Количество элементов больше чем " << value << " равно 0" << std::endl; }
	return EXIT_SUCCESS;
}


int array_serch(std::vector<int> arr, int value)
{
	int left{ 0 };
	int result{-1};
	
	int right = static_cast<int>(arr.size()) - 1;
	while (left <= right) 
	{
		int middle = (left + right) / 2;
		if (arr[middle] > value) 
		{
			result = middle;
			right = middle - 1;
		}
		else
		{
			left = middle + 1;
		}
	}
	if (result == -1) { return -1; }
	return (static_cast<int>(arr.size()) - result);
}