#include <iostream>
#include <string>
#include <Windows.h>


int simple_string_hash(std::string const& s)
{
	int hash_summ = 0;
	for (auto ch : s){ hash_summ += static_cast<int>(ch);}
	return hash_summ;
}

int main()
{
	setlocale(LC_ALL, "rus");  //setting the language standard
	SetConsoleCP(1251);

	std::string inp_string{};
	std::cout << "¬ведите строку: "; std::cin >> inp_string;

	std::cout << simple_string_hash(inp_string);
	return EXIT_SUCCESS;
}