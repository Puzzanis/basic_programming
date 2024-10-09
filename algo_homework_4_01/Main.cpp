#include <iterator>
#include <iostream>
#include <vector>

void print_dynamic_array(int* arr, int logical_size, int actual_size);
void print_dynamic_array1(std::vector<std::string>* arr, int logical_size, int actual_size);

int main()
{
	setlocale(LC_ALL, "rus");  //setting the language standard

	int actual_size{};
	std::cout << "Введите фактичеcкий размер массива: "; std::cin >> actual_size;
	int logical_size{};
	std::cout << "Введите логический размер массива: "; std::cin >> logical_size;
	
	// первый вариант
	int* arr = new int[actual_size];
	print_dynamic_array(arr, logical_size, actual_size);
	delete[] arr;

	// второй вариант
	std::vector<std::string> arr1(actual_size, "_");
	print_dynamic_array1(&arr1, logical_size, actual_size);

	
	return EXIT_SUCCESS;
}

void print_dynamic_array(int* arr, int logical_size, int actual_size)
{
	if (logical_size > actual_size) { std::cout << "Ошибка! Логический размер массива не может превышать фактический!\n"; return; }

	for (int i = 0; i < logical_size; i++)
	{
		std::cout << "Введите arr[" << i << "]: "; std::cin >> arr[i];
	}

	for (int i = 0; i < actual_size; i++)
	{
		if (i <= logical_size - 1) 
		{ 
			std::cout << arr[i] << " "; 
		}
		else { 
			std::cout << "_" << " "; 
		}
		
	}
	std::cout << std::endl;
	std::cout << std::endl;
}



void print_dynamic_array1(std::vector<std::string>* arr, int logical_size, int actual_size)
{
	if (logical_size > actual_size) { std::cout << "Ошибка! Логический размер массива не может превышать фактический!\n"; return; }

	for (int i = 0; i < logical_size; i++)
	{
		std::cout << "Введите arr[" << i << "]: "; std::cin >> arr->at(i);
	}

	copy(arr->begin(), arr->end(), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;
}