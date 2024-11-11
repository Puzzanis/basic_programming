#include "Smart_array.h"


Smart_array::Smart_array(int size) : size_{ size }, buffer{ new int[size] } {};

Smart_array::Smart_array(const Smart_array& obj):Smart_array{ obj.size_ }
{
	std::copy(obj.buffer, obj.buffer + size_, buffer);
}

// оператор присвоения
Smart_array Smart_array::operator=(const Smart_array& rhs) {
	Smart_array copy(rhs);		// вызываем конструктор копирования
	swap(copy);                 // обмениваем значениями
	return *this;

}

int Smart_array::getSize() const { return size_; }

// функция обмена значениями
void Smart_array::swap(Smart_array& other) noexcept
{
	std::swap(buffer, other.buffer);   // обмениваем два указателя
	std::swap(size_, other.size_);    // обмениваем размеры
}

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
	if (index < size_) { return this->buffer[index]; }
	throw std::invalid_argument("Индекс вне диаппазона!");
};

Smart_array::~Smart_array() { delete[] buffer; };

