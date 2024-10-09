#include <iterator>
#include <iostream>
#include <vector>

void print_dynamic_array(int* arr, int logical_size, int actual_size);
int* append_to_dynamic_array(int* arr, int& logical_size, int& actual_size, int new_val);


int main()
{
	setlocale(LC_ALL, "rus");  //setting the language standard

	int actual_size{};
	std::cout << "Введите фактичеcкий размер массива: "; std::cin >> actual_size;
	int logical_size{};
	std::cout << "Введите логический размер массива: "; std::cin >> logical_size;
	auto* arr = new int[actual_size];

	if (logical_size > actual_size) { std::cout << "Ошибка! Логический размер массива не может превышать фактический!\n"; return EXIT_SUCCESS; }

	for (int i = 0; i < logical_size; i++)
	{
		std::cout << "Введите arr[" << i << "]: "; std::cin >> arr[i];
	}

	print_dynamic_array(arr, logical_size, actual_size);
	int new_val{-1};
	
	for (;;)
	{
		if (new_val == 0) { std::cout << "Спасибо! Ваш массив:"; print_dynamic_array(arr, logical_size, actual_size); break; }
		std::cout << "ведите элемент для добавления (введите 0 для выхода):"; std::cin >> new_val;
		arr = append_to_dynamic_array(arr, logical_size, actual_size, new_val);
		print_dynamic_array(arr, logical_size, actual_size);
	}

	delete[] arr;
	return EXIT_SUCCESS;
}

int* append_to_dynamic_array(int* arr, int& logical_size, int& actual_size, int new_val)
{
	if (logical_size < actual_size) 
	{ 
		arr[logical_size] = new_val; 
		logical_size++;
	}
	else
	{
		actual_size *= 2;
		auto* new_arr = new int[actual_size];
		for (int i = 0; i < logical_size; i++) { new_arr[i] = arr[i]; }
		delete[] arr;
		new_arr[logical_size] = new_val;
		arr = new_arr;
	}

	return arr;

}

void print_dynamic_array(int* arr, int logical_size, int actual_size)
{
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
}
