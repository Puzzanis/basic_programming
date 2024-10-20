#include <iostream>
#include <sstream>
#include <string>
#include <vector>
//#include <cmath>
#include <Windows.h>


// Функция для вычисления индекса родителя по индексу потомка
int pyramid_parent_index(int child_index) {
	// Возвращает индекс родителя, используя формулу (child_index - 1) / 2
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
		// - Уровень
		// - Позиция (левый/правый)
		// - Значение родителя
		// - Значение элемента
		std::cout << level << " " << position_str << "(" << arr[parent_index] << ") " << arr[i] << std::endl;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");  //setting the language standard
	SetConsoleCP(1251);

	std::vector<int> inputData;
	std::string s;
	std::cout << "Введите исходный массив: "; std::getline(std::cin, s);
	std::stringstream ss(s);
	std::string word;
	while (ss >> word) {
		inputData.push_back(std::stoi(word));
	}

	print_pyramid(inputData);

	return EXIT_SUCCESS;
}