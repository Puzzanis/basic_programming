#pragma once
#include <iostream>


class Smart_array
{
	int index_{ 0 };
	int size_{ 0 };
public:
	int* buffer;

	explicit Smart_array(int size);
	int get_element(int index) const;
	void add_element(int element);
	~Smart_array();
};
