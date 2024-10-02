#include <iostream>
/*
Сложность алгоритма O(2^n)
по памяти O(n)
*/
long long int fibo(int num);

int main()
{

	std::cout << fibo(50);
	return EXIT_SUCCESS;
}

long long int fibo(int num)
{
	if (num <= 0) return 0;
	else if (num == 1) return 1;
	else return fibo(num - 1) + fibo(num - 2);
}