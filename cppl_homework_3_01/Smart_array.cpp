#include "Smart_array.h"


Smart_array::Smart_array(int size) : size_{size}, buffer{ new int[size] } {};
void Smart_array::add_element(int element) 
{
	if (index_ < size_) 
	{
		this->buffer[index_] = element;
		this->index_++;
		return;
	}
	throw std::out_of_range("Не возможно добавить элемент!");
};

int Smart_array::get_element(int index) const
{
	if (index < size_){ return this->buffer[index]; }
	throw std::invalid_argument("Индекс вне диаппазона!");
};

Smart_array::~Smart_array() { delete[] buffer; };

