﻿#include <fstream> // для файловых потоков
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

struct Matrix
{
	int vertex{ 0 };						//количество вершин
	std::vector <int> visited;				//массив посещенных вершин
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
		if (line.length() < 4) { str >> m.vertex; m.visited.resize(m.vertex); continue; }

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

bool dfs(Matrix& m, int vertex, int prev) {

	m.visited[vertex - 1] = 1;

	for (int j = 0; j < m.vertex; j++) {
		if ((m.matrix[vertex - 1][j] == 1) && (m.visited[j] != 1)) {
			prev = j + 1;
			dfs(m, (j + 1), prev);
		}
		else if ((m.matrix[vertex - 1][j] == 1) && (m.visited[j] == 1) && (vertex != prev)) {
			return true;
		}
	}
	return false;
}

//Алгоритм обхода графа в глубину
std::string ciclic(Matrix& m) {
	std::string ans{};
	for (int i = 0; i < m.vertex; i++) {
		if (m.visited[i] != 1) {
			if (dfs(m, (i + 1), 0))
			{
				ans = "В графе есть цикл!";
				break;
			}
			ans = "В графе нет цикла!";
		}
	}
	return ans;
}


int main()
{
	setlocale(LC_ALL, "Russian");

	Matrix matrix;
	//matrix = read_file("input.txt");
	matrix = read_file("input2.txt");

	std::cout << ciclic(matrix);
	std::cout << std::endl;



	return EXIT_SUCCESS;
}