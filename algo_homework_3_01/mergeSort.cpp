#include "Merge.h"
#include "mergeSort.h"

std::vector<int> mergeSort(std::vector<int> &arr)
{
	if (arr.size() == 1) return arr;
	
	size_t mid = static_cast<int>(arr.size() / 2);

	std::vector<int> arr_l(arr.begin(), arr.begin() + mid);
	std::vector<int> arr_r(arr.begin() + mid, arr.end());

	std::vector<int> l_sort = mergeSort(arr_l);
	std::vector<int> r_sort = mergeSort(arr_r);
	
	return merge(l_sort, r_sort);
}