#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

struct Matrix
{
	int vertex{ 0 };						//количество вершин
	std::vector <int> cids;					//
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
		if (line.length() < 4) { str >> m.vertex; m.cids.resize(m.vertex); continue; }

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

void dfs(Matrix& m, int vertex, const int &cid) {

	m.cids[vertex - 1] = cid;

	for (int j = 0; j < m.vertex; j++) {
		if ((m.matrix[vertex - 1][j] == 1) && (m.cids[j] == 0)) {
			dfs(m, (j + 1), cid);
		}
	}
}

//Алгоритм обхода графа в глубину
void component(Matrix& m) 
{
	int summ_cid = 1;	//общее количество компонентов связанности

	for (int i = 0; i < m.vertex; i++) {
		if (m.cids[i] == 0) {
			dfs(m, (i + 1), summ_cid);
			summ_cid++;
		}
	}
	for (int i = 0; i < m.cids.size(); i++) 
	{
		std::cout << i + 1 << " - " << m.cids[i] << std::endl;
	}
	std::cout << "Количество компонентов связности в графе: " << summ_cid - 1;
}


int main()
{
	setlocale(LC_ALL, "Russian");

	Matrix matrix;
	matrix = read_file("input.txt");
	//matrix = read_file("input2.txt");

	std::cout << "Принадлежность вершин компонентам связности: \n";
	component(matrix);


	return EXIT_SUCCESS;
}