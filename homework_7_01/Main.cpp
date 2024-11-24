#include <iostream>
#include <map>
#include <vector>
#include <algorithm> 


int main()
{
	std::string inputWord = "Hello world!!";

	std::map<char, int> chars;
	
	//добавляем элементы в словарь и их частоту
	for (auto const ch : inputWord)
	{
		chars.insert({ ch, 0 });
		chars[ch]++;
	}
	std::vector< std::pair< char, int > > vec(chars.begin(), chars.end());
	std::sort(vec.begin(), vec.end(), [=](auto p1, auto p2) {return p1.second > p2.second; });

	std::cout << "[IN]: " << inputWord << std::endl;
	std::cout << "[OUT]: " << std::endl;
	for (auto p : vec)
	{
		std::cout << p.first << ' ' << p.second << std::endl;
	}

	return EXIT_SUCCESS;
}