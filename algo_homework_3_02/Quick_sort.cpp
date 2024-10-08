#include "Quick_sort.h"

void quickSort(std::vector<int> *arr, int start, int size)
{
	int pivot = arr->at(size);
	int right_indx = size;
	int left_indx{ start };
	while (left_indx < right_indx)
	{
		while(arr->at(left_indx) < pivot) left_indx++;
		while (arr->at(right_indx) > pivot) right_indx--;
		if (left_indx <= right_indx ) 
		{
			std::swap(arr->at(left_indx), arr->at(right_indx));
			left_indx++;
			right_indx--;
		}
	}
	if (right_indx > 0) quickSort(arr, 0, right_indx);
	if (size > left_indx) quickSort(arr, left_indx, size);
}