#include <fstream> // для файловых потоков
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

//Алгоритм обхода графа в ширину
void BFS(Matrix &m, int startVertex)
{
	std::vector<int> q;
	m.visited[startVertex-1] = 1;
	q.push_back(startVertex);

	while (!q.empty()) {

		int currentVertex = q.front();
		std::cout << currentVertex << " ";
		q.erase(q.begin());

		for (int i = 0; i < m.vertex; i++) {
			if (m.matrix[currentVertex - 1][i] == 1 && m.visited[i] != 1) {
				m.visited[i] = 1;
				q.push_back(i+1);
			}
		}
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");

	Matrix matrix;
	matrix = read_file("input.txt");

	int start_vertex;
	for(;;)
	{
		std::system("cls");
		std::cout << "В графе " << matrix.vertex << " вершин.Введите номер вершины, с которой начнётся обход : "; std::cin >> start_vertex;
		if (start_vertex > 0 && start_vertex <= matrix.vertex) break;
	}
	
	std::cout << "Порядок обхода вершин: ";
	BFS(matrix, start_vertex);
	std::cout << std::endl;


	return EXIT_SUCCESS;
}