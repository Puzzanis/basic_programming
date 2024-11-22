#pragma once

#include <iostream>
#include <vector>


class Counter {
private:
	int m_counter{ 0 };
	int summ{ 0 };
public:
	Counter() = default;
	int get_sum() const;
	int get_count() const;
	void operator()(int a);
};
