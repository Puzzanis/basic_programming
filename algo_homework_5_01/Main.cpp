﻿#include <iostream>
#include <string>
#include <vector>


// Функция для вычисления индекса родителя по индексу потомка
int pyramid_parent_index(int child_index) {
	return (child_index - 1) / 2;
}

// Функция для определения, является ли элемент левым потомком
bool pyramid_is_left(int index) {
	return (index % 2 == 1);
}

// Функция для определения уровня элемента
int pyramid_level(int index) {
	return static_cast<int>(log2(index + 1));
}

// Функция для вывода пирамиды
void print_pyramid(std::vector<int> arr) {

	std::cout << "Пирамида:" << std::endl;
	//печатаем корень
	std::cout << 0 << " root(" << arr[0] << ") " << arr[0] << std::endl;

	// Перебираем все элементы массива, начиная со второго
	for (int i = 1; i < arr.size(); ++i) {
		// Вычисляем индекс, уровень и позицию текущего элемента
		int parent_index = pyramid_parent_index(i);
		int level = pyramid_level(i);
		std::string position_str = pyramid_is_left(i) ? "left" : "right";

		// Выводим информацию о текущем элементе:
		std::cout << level << " " << position_str << "(" << arr[parent_index] << ") " << arr[i] << std::endl;
	}
}

// Функция для исходного массива
void print_arr(std::vector<int> const& arr)
{
	std::cout << "Исходный массив: ";
	for (auto val : arr) { std::cout << val << " "; }
	std::cout << std::endl;
}

int main()
{
	setlocale(LC_ALL, "rus");  //setting the language standard
	SetConsoleCP(1251);

	std::vector<int> inputData{ 1, 3, 6, 5, 9, 8 };
	std::vector<int> inputData1{ 94, 67, 18, 44, 55, 12, 6, 42 };
	std::vector<int> inputData2{ 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
	

	print_arr(inputData);
	print_pyramid(inputData);
	std::cout << std::endl;

	print_arr(inputData1);
	print_pyramid(inputData1);
	std::cout << std::endl;

	print_arr(inputData2);
	print_pyramid(inputData2);

	return EXIT_SUCCESS;
}