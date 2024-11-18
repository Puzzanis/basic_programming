#include "Divided_by_3.h"


void Divided_by_3::get_sum() const
{
	std::cout << "get_sum() = " << summ << std::endl;
};
void Divided_by_3::get_count() const
{
	std::cout << "get_count() = " << m_counter << std::endl;
};

void Divided_by_3:: operator()()
{
	int count = 0;
	int summ = 0;
	for (auto a : arr)
	{
		if (a % 3 == 0)
		{
			if (a == 0) continue;
			summ += a;
			++count;
		}
	}
	this->summ = summ;
	this->m_counter = count;
}