#pragma once

#include <iostream>
#include <vector>

class Divided_by_3 {
protected:
	std::vector<int> arr;
	int m_counter{ 0 };
	int summ{ 0 };
public:
	Divided_by_3(const std::vector<int>& arra)
	{
		this->arr = arra;
	}
	void get_sum() const;
	void get_count() const;
	void operator()();
};
