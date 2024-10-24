#include <string>﻿
#include <fstream>
#include <iostream>

#include <sstream>
#include <vector>

struct Matrix
{
	int vertex{ 0 };						//количество вершин
	std::vector<std::vector <int>> matrix;  //матрица смежности
};

Matrix read_file(std::string const& name_file)
{
	Matrix m;
	std::string line;
	std::ifstream infile;
	infile.open(name_file, std::ios::binary);
	while (std::getline(infile, line))
	{
		std::vector<int> temp;
		std::istringstream str(line);
		if (line.length() < 4) { str >> m.vertex;  continue; }

		int n;
		while (str >> n)
		{
			temp.push_back(n);
		}
		m.matrix.push_back(temp);
	}
	infile.close();
	return m;
}

void print(Matrix& m) {

	std::string res{};
	
	for (int i = 0; i < m.vertex; i++) {
		std::string arc{ };
		for (int j = 0; j < m.vertex; j++) {
			if (m.matrix[i][j] == 1) {
				arc += std::to_string(j+1) + ' ';
			}
		}
		std::cout << i + 1 << ": " << ((arc.length() == 0)?"нет": arc) << std::endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	Matrix matrix;
	matrix = read_file("input.txt");

	std::cout << "Текстовый вид орграфа:\n";
	print(matrix);


	return EXIT_SUCCESS;
}