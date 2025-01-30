#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <span>
#include <thread>
#include <vector>


template<class T>
void sumVectors(const std::span<T> v1, const std::span<T> v2, std::vector<T>& sumV)
{
	std::vector<T> rez(v1.size());
	std::transform(std::begin(v1), std::end(v1), std::begin(v2), std::begin(rez), std::plus<T>());
	sumV.insert(sumV.end(), rez.begin(), rez.end());
}

template<class T>
std::span<T> span(int& start, int& end, const std::span<T>& v)
{
	return std::span(v).subspan(start, end);
}

template<class T>
void funcStart(int countThread, int size, std::vector<T>& v1, std::vector<T>& v2, std::vector<T>& sumV)
{
	std::vector<std::thread> TV;
	int shift = v1.size() / countThread;
	for (int i = 0; i < countThread; ++i)
	{
		int start = i * shift;
		auto a = span<int>(start, shift, v1);
		auto b = span<int>(start, shift, v2);
		TV.push_back(std::thread(sumVectors<int>, a, b, std::ref(sumV)));
	}

	for (auto& t : TV)
	{
		t.join();
	}
}

template<class T>
void generateVector(int count, std::vector<T>& v)
{
	std::vector<T> v1(count);
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 1'000'000);
	auto rand_num([=]() mutable {return dis(gen); });
	std::generate(v1.begin(), v1.end(), rand_num);

	v.insert(v.end(), v1.begin(), v1.end());
}


int main()
{
	setlocale(0, "");

	std::vector<int> v1;
	std::vector<int> v2;
	std::vector<int> sumV;

	
	std::vector<int> countNumbers{ 1'000, 10'000, 100'000, 1'000'000 };
	std::vector<int> countThreads{ 1, 2, 4, 8, 16 };
	std::vector<std::vector<double>> TimeRezult(countThreads.size());

	std::cout << "Количество аппаратных ядер - " << std::thread::hardware_concurrency() << std::endl;
	std::cout << std::endl;
	
	for(int i = 0; i < countThreads.size(); ++i)
	{
		for (int count : countNumbers)
		{
			generateVector(count, v1);
			generateVector(count, v2);
			auto start = std::chrono::high_resolution_clock::now();
			{
				funcStart(countThreads[i], v1.size(), v1, v2, sumV);
			}
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time = end - start;
			TimeRezult[i].push_back(time.count());
			v1.clear();
			v2.clear();
			sumV.clear();
		}
	}

	//вывод на экран
	for (int i = 0; i < countNumbers.size(); ++i)
	{
		std::cout << "\t\t\t" << countNumbers[i];
	}
	std::cout << std::endl;
	for (int i = 0; i < TimeRezult.size(); ++i)
	{
		std::cout << countThreads[i] << " потоков";
		for (int j = 0; j < TimeRezult[i].size(); ++j)
		{
			std::cout << "\t\t" << TimeRezult[i][j];
		}
		std::cout << std::endl;
	}
	
	return 0;
}
