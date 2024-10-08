#include "Count_Sort.h"

std::vector<int> count_Sort(std::vector<int> arr, const int K)
{
	std::vector<int> counts(K+1);
	for (int val : arr) 
	{ 
		counts.at(val) += 1; 
	}

	int c = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		while (counts[c] == 0) { c++; }
		arr[i] = c;
		counts[c] -= 1;
	}

	return arr;
}