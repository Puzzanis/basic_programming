#include "Counter.h"


int Counter::get_sum() const
{
	return this->summ;
};

int Counter::get_count() const
{
	return this->m_counter;
}

void Counter:: operator()(int a)
{
	if (a % 3 == 0 && a != 0)
	{
		this->summ += a;
		++this->m_counter;
	}
}