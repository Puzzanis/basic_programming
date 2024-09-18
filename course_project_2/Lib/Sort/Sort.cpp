#include "Sort.h"

void bubbleSort(std::vector<int>& arr, int size, std::vector<Vehicle*>& vehicles) {
	while (size--)
	{
		bool swapped = false;

		for (int i = 0; i < size; i++)
		{
			if (vehicles[arr[i]-1]->get_last_race() > vehicles[arr[i + 1] - 1]->get_last_race())
			{
				std::swap(arr[i], arr[i + 1]);
				swapped = true;
			}
		}

		if (swapped == false)
			break;
	}

}