#pragma once
#include <iostream>


class Smart_array
{
	int index_{ 0 };
	int size_{ 0 };
public:
	int* buffer;

	explicit Smart_array(int size);
	Smart_array(const Smart_array& obj);
	Smart_array operator=(const Smart_array& rhs);
	
	void swap(Smart_array& other) noexcept;
	int get_element(int index) const;
	void add_element(int element);
	int getSize() const;
	~Smart_array();
};
