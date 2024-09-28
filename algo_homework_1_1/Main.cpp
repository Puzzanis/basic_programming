#include <iostream>

int calc(int* arr, int size);

int main()
{
	int a[] = {1,2,3,4,5,6,7,8,10};

	std::cout << calc(a, sizeof(a)/sizeof(a[0]));
	return EXIT_SUCCESS;
}

//функция суммы разности двух соседних элементов массива
int calc(int* arr, int size)
{
	int ans = 0;						//O(1)
	for (int i = 1; i < size; i++)		//O(n)
	{
		ans += arr[i] - arr[i - 1];		//O(1)
	}
	return ans;
}