#include <iostream>
/*
Сложность O(2^n)
по памяти O(n)
*/
int fibo(int num) { return (num <= 0) ? 0 : (num == 1) ? 1 : fibo(num - 1) + fibo(num - 2); }

int main()
{

	std::cout << fibo(10);
	return EXIT_SUCCESS;
}
