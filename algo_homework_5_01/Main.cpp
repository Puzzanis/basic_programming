#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <Windows.h>


class Heap
{
private:
	std::vector<int> data_;
public:
	Heap(std::vector<int> const& mass) : data_{ mass } {}

	int getRoot() { return data_[0]; }
	int get_value(int index) {return data_[index];}
	int get_left_index(int parent_index) const { return 2 * parent_index + 1; }
	int get_right_index(int parent_index) const { return 2 * parent_index + 2; }
	int get_parent_index(int child_index) const {return (child_index - 1) / 2;}
};

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

	Heap h(inputData);

	std::cout << "Пирамида:\n";
	int tmp{ 2 };
	int row{ 1 };
	for (int i = 0; i < inputData.size(); i++)
	{
		if (tmp == i+1) { tmp *= 2; row++; }
		int left = h.get_left_index(i);
		int right = h.get_right_index(i);
		if (i == 0) { std::cout << i << " root " << h.getRoot() << std::endl;}
		
		if (left < inputData.size()) { std::cout << row << " left(" << h.get_value(h.get_parent_index(left)) << ") " << h.get_value(left) << std::endl; }
		if (right < inputData.size()) { std::cout << row << " right(" << h.get_value(h.get_parent_index(right)) << ") " << h.get_value(right) << std::endl; }
	}
	

	return EXIT_SUCCESS;
}