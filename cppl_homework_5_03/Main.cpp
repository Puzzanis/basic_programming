#include<algorithm>
#include <iostream>
#include <vector>
#include "Counter.h"

int main()
{
	std::vector<int> numbers = { 4, 1, 3, 6, 25, 54 };
	Counter counter = std::for_each(numbers.begin(), numbers.end(), Counter());
	std::cout << "[OUT]: get_sum() = " << counter.get_sum() << std::endl;
	std::cout << "[OUT]: get_count() = " << counter.get_count() << std::endl;

	return 0;
}