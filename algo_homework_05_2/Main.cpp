#include <iostream>
#include <sstream>
#include <string>
#include <vector>
//#include <cmath>
#include <Windows.h>


// ������� ��� ���������� ������� �������� �� ������� �������
int pyramid_parent_index(int child_index) {
	// ���������� ������ ��������, ��������� ������� (child_index - 1) / 2
	return (child_index - 1) / 2;
}

// ������� ��� �����������, �������� �� ������� ����� ��������
bool pyramid_is_left(int index) {
	return (index % 2 == 1);
}

// ������� ��� ����������� ������ ��������
int pyramid_level(int index) {
	return static_cast<int>(log2(index + 1));
}

// ������� ��� ������ ��������
void print_pyramid(std::vector<int> arr) {

	std::cout << "��������:" << std::endl;
	//�������� ������
	std::cout << 0 << " root(" << arr[0] << ") " << arr[0] << std::endl;

	// ���������� ��� �������� �������, ������� �� �������
	for (int i = 1; i < arr.size(); ++i) {
		// ��������� ������, ������� � ������� �������� ��������
		int parent_index = pyramid_parent_index(i);
		int level = pyramid_level(i);
		std::string position_str = pyramid_is_left(i) ? "left" : "right";

		// ������� ���������� � ������� ��������:
		// - �������
		// - ������� (�����/������)
		// - �������� ��������
		// - �������� ��������
		std::cout << level << " " << position_str << "(" << arr[parent_index] << ") " << arr[i] << std::endl;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");  //setting the language standard
	SetConsoleCP(1251);

	std::vector<int> inputData;
	std::string s;
	std::cout << "������� �������� ������: "; std::getline(std::cin, s);
	std::stringstream ss(s);
	std::string word;
	while (ss >> word) {
		inputData.push_back(std::stoi(word));
	}

	print_pyramid(inputData);

	return EXIT_SUCCESS;
}