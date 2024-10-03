#include <iostream>
#include <vector>

/*

*/

unsigned long int fibo(int num);
unsigned long int fibo_mem(int num);

std::vector<int> save_result(50);

int main()
{

	std::cout << fibo_mem(47) << std::endl;
	return EXIT_SUCCESS;
}

unsigned long int fibo(int num) { return (num <= 1) ? num : fibo_mem(num - 1) + fibo_mem(num - 2); }
unsigned long int fibo_mem(int num)
{
	if (save_result[num] == 0) { save_result[num] = fibo(num); }
	
	return  save_result[num];
}