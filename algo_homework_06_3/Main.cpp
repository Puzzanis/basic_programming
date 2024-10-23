#include <iostream>
#include <string>
#include <Windows.h>


uint64_t hash_function(std::string const& s, int const indx, int const length)
{
	int p{ 29 };
	int mod{1000};
	uint64_t hash_summ{ 0 };
	uint64_t tmp{ 1 };
	for (int i = indx; i < (indx + length); i++)
	{
		hash_summ += tmp * static_cast<short>(s[i]);
		tmp *= p;
	}
	return hash_summ % mod;
}

int find_substring_light_rabin_karp(std::string const& s, const char c, int const length, uint64_t const * etalon)
{
	int count{ 0 };
	while (count < s.length())
	{
		if (s[count] == c) 
		{ 
			uint64_t hash_substring = hash_function(s, count, length);
			if (hash_substring == *etalon)
			{
				return count;
			}
			
		}
		count += 1;
	}
	return -1;
}

int main()
{
	setlocale(LC_ALL, "rus");  //setting the language standard
	SetConsoleCP(1251);

	std::string input_string{};
	std::cout << "Введите строку, в которой будет осуществляться поиск : "; std::cin >> input_string;

	for (;;) {
		std::string input_word{};
		std::cout << "Введите подстроку, которую нужно найти: "; std::cin >> input_word;

		uint64_t hash_etalon = hash_function(input_word, 0, static_cast<int>(input_word.length()));
		int indx = find_substring_light_rabin_karp(input_string, input_word[0], static_cast<int>(input_word.length()), &hash_etalon);

		if (indx != -1)
		{
			std::cout << "Подстрока " << input_word << " найдена по индексу " << indx  << std::endl;
		}
		else
		{
			std::cout << "Подстрока " << input_word << " не найдена " << std::endl;
		}
		

		if (input_word == "exit") break;
	}

	return EXIT_SUCCESS;
}