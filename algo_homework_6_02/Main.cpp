#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>


int simple_string_hash(std::string const& s, int const &p, int const &n)
{
	uint64_t hash_summ{0};
	uint64_t tmp{ 1 };
	for (int i = 0; i < s.length(); i++)
	{
		hash_summ += tmp * static_cast<short>(s[i]);
		tmp *= p;
	}
	return hash_summ % n;
}

int main()
{
	setlocale(LC_ALL, "rus");  //setting the language standard
	SetConsoleCP(1251);
	
	//������� ����� p
	int p{0};
	std::cout << "������� p: "; std::cin >> p;
	
	//������ n
	int n{ 0 };
	std::cout << "������� n: "; std::cin >> n;

	for (;;) {
		//������
		std::string inp_string{};
		std::cout << "������� ������: "; std::cin >> inp_string;

		std::cout << "��� ������ " << inp_string << " = " << simple_string_hash(inp_string, p, n); std::cout << std::endl;

		if (inp_string == "exit") break;
	}

	return EXIT_SUCCESS;
}