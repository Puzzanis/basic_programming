#include <iostream>
#include <vector>
#include <Windows.h>

void print_dynamic_array(int* arr, int logical_size, int actual_size);
int* remove_dynamic_array_head(int* arr, int& logical_size, int& actual_size);


int main()
{
	setlocale(LC_ALL, "rus");  //setting the language standard
	SetConsoleCP(1251);

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
	std::string answer{};

	for (;;)
	{
		if (answer == "нет") { std::cout << "Спасибо! "; print_dynamic_array(arr, logical_size, actual_size); break; }
		std::cout << "Удалить первый элемент? "; std::cin >> answer;
		if (answer == "да")
		{
			if (logical_size <= 0) { std::cout << "Невозможно удалить первый элемент, так как массив пустой. До свидания!\n";  break;}
			arr = remove_dynamic_array_head(arr, logical_size, actual_size);
			print_dynamic_array(arr, logical_size, actual_size);
		}
		
	}

	delete[] arr;
	return EXIT_SUCCESS;
}

int* remove_dynamic_array_head(int* arr, int& logical_size, int& actual_size)
{
	if (logical_size < 1) return arr;
	if ((logical_size - 1) > actual_size/3)
	{
		
		for (int i = 0; i < logical_size-1; i++) { arr[i] = arr[i+1]; }
		logical_size--;
	}
	else
	{
		actual_size /= 3;
		auto* new_arr = new int[actual_size];
		for (int i = 0; i < logical_size-1; i++) { new_arr[i] = arr[i+1]; }
		delete[] arr;
		arr = new_arr;
		logical_size--;
	}

	return arr;

}

void print_dynamic_array(int* arr, int logical_size, int actual_size)
{
	std::cout << "Ваш динамический массив: ";
	if (logical_size < 1) { std::cout << "_\n"; return; }
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
